// In use: https://github.com/rtek1000/RF_Magic_Controller_6803_IC/tree/main/Arduino_Modified_Hardware/MCP4725

#include "stm8s.h"

#define MCP4725_Addr 0x62
#define HALF_DAC_OUT 1
// #define FULL_DAC_OUT 1

#define I2C_Speed 50000 // 100000
#define MAX_TIMEOUT 0xFFFFF

#define dead_time() { /* _asm("nop"); _asm("nop"); */ }

int I2C_WriteRegister2(u8 u8_regAddr, u8 u8_NumByteToWrite, u8 *u8_DataBuffer);
void set_dac_fast(u16 value);
void I2C_Setup(u8 u8_regAddr);

void setup() {
  // put your setup code here, to run once:
  I2C_Setup(0x1);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 500; i++) {
    set_dac_fast(i);
  }
}

void set_dac_fast(u16 value) {
  uint32_t u32_dac_out_val = 0;
  // dac out:
  // 5V: 4095
  // 0V: 0
  // 5 / 4096 = 0.001220703
  //
  // val_prog:
  // 5000 = 5V
  // 1000 = 1V
  // val_prog / 1000 = V
  // V / 0.001220703 = dac value

  //float f_dac_out_val = val_prog; // no Flash space!!!
  //f_dac_out_val /= 1000.0;
  //f_dac_out_val /= 0.001220703;

  u32_dac_out_val = value; // 0-100
#ifdef HALF_DAC_OUT
  u32_dac_out_val *= 5000; // 500
#endif
#ifdef FULL_DAC_OUT
  u32_dac_out_val *= 10000; // 1000
#endif
  u32_dac_out_val /= 1220; // 1220
  if (u32_dac_out_val > 4095) u32_dac_out_val = 4095;

  value = u32_dac_out_val;

  u8 buff[2];
  buff[0] = (value >> 8) & 0x0F;
  buff[1] = value & 0xFF;
  //  buff[2] = buff[0];
  //  buff[3] = buff[1];

  I2C_WriteRegister2(MCP4725_Addr, 2, buff);
}


void I2C_Setup(u8 u8_regAddr)
{
  GPIO_DeInit(GPIOB);

  GPIO_Init(GPIOB, GPIO_PIN_4, GPIO_MODE_OUT_OD_HIZ_FAST);

  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_OD_HIZ_FAST);

  CLK_PeripheralClockConfig(CLK_PERIPHERAL_I2C, ENABLE);

  I2C_DeInit();

  I2C_Init(I2C_Speed, u8_regAddr, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, (CLK_GetClockFreq() / 1000000));

  // I2C->ITR = I2C_ITR_ITEVTEN;                      // enable error interrupts
  //  I2C_ITR_ITEVTEN = 1;          //Event  Enables               : SB, ADDR, ADD10, STOPF, BTF, WUFH
  //  I2C_ITR_ITBUFEN = 1;          //Buffer Enables (if ITEVTEN)  : RXNE, TXE
  //  I2C_ITR_ITERREN = 1;          //Error  Enables               : BERR, ARLO, AF, OVR

  I2C_Cmd(ENABLE);

  // attachInterrupt(INT_I2C & 0xFF, I2C_interr, CHANGE);
}

/******************************************************************************
  Function name : I2C_WriteRegister2
  Description   : write defined number bytes to slave memory starting with defined offset
  Input param   : offset in slave memory, number of bytes to write, starting address to send
  Return        : None.
  See also      : i2c_master_poll.c - STM8 optimized I2C examples (AN3281)
*******************************************************************************/
int I2C_WriteRegister2(u8 u8_regAddr, u8 u8_NumByteToWrite, u8 *u8_DataBuffer)
{
  int err = 0;

  u32 tout = MAX_TIMEOUT;

  while (I2C->SR3 & I2C_SR3_BUSY) { // Wait while the bus is busy
    I2C->CR2 |= I2C_CR2_STOP; // STOP=1, generate stop

    u32 tout2 = MAX_TIMEOUT;
    while (I2C->CR2 & I2C_CR2_STOP) { // wait until stop is performed
      if (tout2 > 0) {
        tout2--;
      } else {
        err |= 1;
        break;
      }
    }

    if (tout > 0) {
      tout--;
    } else {
      err |= 2;
      break;
    }
  }

  //I2C_GenerateSTART(ENABLE);
  I2C->CR2 |= 1; // START=1, generate start
  tout = MAX_TIMEOUT;
  while ((I2C->SR1 & 1) == 0) { // Wait for start bit detection (SB)
    if (tout > 0) {
      tout--;
    } else {
      err |= 4;
      break;
    }
  }

  dead_time(); // SB clearing sequence

  I2C->DR = (u8)(u8_regAddr << 1);                 // Send 7-bit device address & Write (R/W = 0)

  tout = MAX_TIMEOUT;
  while (!(I2C->SR1 & 2)) {    // Wait for address ack (ADDR)
    if (tout > 0) {
      tout--;
    } else {
      err |= 8;
      break;
    }
  }
  (void)I2C->SR3; // ADDR=1, cleared by reading SR1 register followed by reading SR3
  dead_time(); // ADDR clearing sequence

  while (u8_NumByteToWrite--)
  { // write data loop start
    tout = MAX_TIMEOUT;
    while (!(I2C->SR1 & 0x80)) {                // test EV8 - wait for TxE
      if (tout > 0) {
        tout--;
      } else {
        err |= 16;
        break;
      }
    }

    I2C->DR = *u8_DataBuffer++;                           // send next data byte
  }
  tout = MAX_TIMEOUT;
  while ((I2C->SR1 & 0x84) != 0x84) { // Wait for TxE & BTF
    if (tout > 0) {
      tout--;
    } else {
      err |= 32;
      break;
    }
  }
  dead_time(); // clearing sequence

  I2C->CR2 |= 2; // generate stop here (STOP=1)

  tout = MAX_TIMEOUT;
  while (I2C->CR2 & 2) { // wait until stop is performed
    if (tout > 0) {
      tout--;
    } else {
      err |= 64;
      break;
    }
  }

  return err;
}
