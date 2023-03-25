// Source: https://embedded-lab.com/blog/starting-stm8-microcontrollers/15/

#include"stm8s.h"

void IWDG_setup(void);
void IWDG_reset(void);

void setup() {
  // put your setup code here, to run once:

  IWDG_setup();
}

void loop() {
  // put your main code here, to run repeatedly:

  IWDG_reset();
}

void IWDG_setup(void) {
  IWDG_Enable();
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG_SetPrescaler(IWDG_Prescaler_256);
  IWDG_SetReload(0xFF);
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Disable);
}

void IWDG_reset(void) {
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG_ReloadCounter();
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Disable);
}
