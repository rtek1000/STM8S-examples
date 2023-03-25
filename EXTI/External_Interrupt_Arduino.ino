// Source: https://github.com/tenbaht/sduino/issues/127
// In use: https://github.com/rtek1000/RF_Magic_Controller_6803_IC/blob/main/Arduino_Modified_Hardware/Test_remote_control.ino

// test pin change interrupt on pin PC3
// the pin level on PC3 is copied onto the built-in led 

static void portc_irq (void) {
  digitalWrite(LED_BUILTIN,digitalRead(PC3));
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW); //led on

  pinMode (PC3, INPUT_PULLUP);
  attachInterrupt(2,portc_irq, 0); // mode is not implemented in sduino, so we do the config manually after

  disableInterrupts(); // EXTI->CR1 only writable under disabled interrupts (CCR=3)
  EXTI->CR1 = 0x30; // set falling+rising interrupt for all pins on port C
  GPIOC->CR2 = 0x08; // enable ext interrupt on pin PC3
  enableInterrupts();
}

void loop() {
}
