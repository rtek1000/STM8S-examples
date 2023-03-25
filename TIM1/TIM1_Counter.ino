// Source: https://sites.google.com/site/klaasdc/stm8s-projects/rpm-counter-1
// In use: https://github.com/rtek1000/RF_Magic_Controller_6803_IC/blob/main/Arduino_Modified_Hardware/Test_remote_control.ino
#include "stm8s.h"

unsigned int _width_us = 0;

void setup() {
  // put your setup code here, to run once:
  
  TIM1_DeInit();
  TIM1_TimeBaseInit(7, TIM1_COUNTERMODE_UP, 65535, 0);
  TIM1_Cmd(ENABLE);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read:
  _width_us = TIM1_GetCounter(); // step: 0.5us
  
  // reset:
  TIM1_SetCounter(0);
}
