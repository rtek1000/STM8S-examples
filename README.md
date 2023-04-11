# STM8S-examples
Examples found on the Internet for using the resources of the STM8 since the ST does not seem to support this line of low cost microcontrollers very well.

Tutorial:
- Embedded Lab: [Starting STM8 Microcontrollers](https://embedded-lab.com/blog/starting-stm8-microcontrollers/)
- - Hardware Tools (STlink)
- - Software Tools (IDE)
- - General Purpose Input Output (GPIO)
- - Clock System (CLK)
- - External Interrupt (EXTI)
- - Beeper (BEEP)
- - Alphanumeric LCD (Display HD44780)
- - Analog-to-Digital Converter (ADC)
- - Analog Watchdog (AWD)
- - Independent Watchdog (IWDG)
- - Window Watchdog (WWDG)
- - Time Base Generation (TIM2)
- - Timer Interrupt (TIM4)
- - General Purpose Pulse Width Modulation (TIM2 PWM)
- - Advanced Pulse Width Modulation (TIM1 PWM)
- - Timer Input Capture (TIM1 & TIM2)
- - Serial Communication (UART)
- - Serial Peripheral Interface (SPI)
- - Inter-Integrated Circuit (I2C)
- Embedded Lab: [Continuing the STM8 Expedition](https://embedded-lab.com/blog/continuing-stm8-microcontroller-expedition/)
- - ADC Interrupt
- - Multi-Channel ADC with Scan Mode
- - Creating Delays using Basic Timer
- - Encoder Interface
- - One Pulse Mode (OPM - Timer)
- - PWM Input Mode (PWMI - Timer)
- - PWM Duty Capture using Software
- - Low Power Sleep Mode
- - Auto Wakeup Mode (AWU)
- - True Data EEPROM
- - Internal Flash Memory
- - UART Interrupt
- - Software SPI – MAX6675
- - Driving LCD with Hardware SPI and by Bit-Banging Method
- - TFT Display – ST7735
- Embedded Lab: [STM8 Microcontrollers – the Final Chapters](https://embedded-lab.com/blog/stm8-microcontrollers-final-chapters/)
- - Software I2C – DS1307
- - Driving LCD with I2C Interface (Display HD44780)
- - OLED Display – SSD1306/SSD1309
- - Bit-Banging PCD8544 GLCD
- - One Wire (OW) – DS18B20
- - One Wire – DHT11
- - Single Capacitive Touch
- - Multi Capacitive Touch
- - - All tutorial codes and PDF document of these tutorials are available: [here](https://libstock.mikroe.com/projects/view/2056/stm8-microcontroller-tutorials).
- Klaasdc: [STM8S Projects](https://sites.google.com/site/klaasdc/stm8s-projects)
- - 16bit to BCD Conversion
- - A/D tacho conversion
- - Elevator codelock
- - RPM Counter
- YouTube: [How to use STM8S Controller with Arduino IDE | SDUINO](https://www.youtube.com/watch?v=8CfD1d4Z_Vk)
- YouTube Playlist (42 videos): [STM8 Microcontroller Tutorials](https://www.youtube.com/playlist?list=PL-EErZRpDPIW2_hgHZEkgHINcSUKQS4LY)

Arduino Core:
- https://tenbaht.github.io/sduino/
- https://github.com/tenbaht/sduino
- https://github.com/stm32duino/Arduino_Core_STM8

[The STM8S003 is almost identical to the STM8S103, the only difference is a smaller EEPROM area:](https://github.com/tenbaht/sduino/issues/90)

STM8S003F3: https://www.st.com/en/microcontrollers-microprocessors/stm8s003f3.html
- Data memory: 128 bytes true data EEPROM; endurance up to 100 k write/erase cycles 

STM8S103F3: https://www.st.com/en/microcontrollers-microprocessors/stm8s103f3.html
- Data memory: 640 byte true data EEPROM; endurance 300 kcycle 

----------------

- This project uses STM8S003F3P6, on board W1209 - Thermostat (or timer)
https://github.com/rtek1000/W1209-firmware-modified

