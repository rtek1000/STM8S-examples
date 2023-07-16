# STM8S-examples
Examples found on the Internet for using the resources of the STM8 since the ST does not seem to support this line of low cost microcontrollers very well.

# Tutorials:

Start understanding STM8 with this tutorial:

- Embedded Lab: [Starting STM8 Microcontrollers](https://embedded-lab.com/blog/starting-stm8-microcontrollers/)
- - [Hardware Tools (STlink)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/3/)
- - [Software Tools (IDE)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/4/)
- - [General Purpose Input Output (GPIO)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/8/)
- - [Clock System (CLK)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/9/)
- - [External Interrupt (EXTI)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/10/)
- - [Beeper (BEEP)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/11/)
- - [Alphanumeric LCD (Display HD44780)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/12/)
- - [Analog-to-Digital Converter (ADC)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/13/)
- - [Analog Watchdog (AWD)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/14/)
- - [Independent Watchdog (IWDG)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/15/)
- - [Window Watchdog (WWDG)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/16/)
- - [Time Base Generation (TIM2)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/18/)
- - - [Timer Overview](https://embedded-lab.com/blog/starting-stm8-microcontrollers/17/)
- - [Timer Interrupt (TIM4)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/19/)
- - [General Purpose Pulse Width Modulation (TIM2 PWM)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/20/)
- - [Advanced Pulse Width Modulation (TIM1 PWM)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/21/)
- - [Timer Input Capture (TIM1 & TIM2)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/22/)
- - [Serial Communication (UART)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/24/)
- - - [Communication Overview](https://embedded-lab.com/blog/starting-stm8-microcontrollers/23/)
- - [Serial Peripheral Interface (SPI)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/25/)
- - [Inter-Integrated Circuit (I2C)](https://embedded-lab.com/blog/starting-stm8-microcontrollers/26/)
- - [Some Useful Tips](https://embedded-lab.com/blog/starting-stm8-microcontrollers/27/)

----------

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

----------

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

----------

Tutorial to make better use of memory:

- lujji: [Serial bootloader for STM8](https://lujji.github.io/blog/serial-bootloader-for-stm8/)
- - This article will cover developing a serial bootloader for STM8S microcontrollers.
- lujji: [Mixing C and assembly on STM8](https://lujji.github.io/blog/mixing-c-and-assembly-on-stm8/)
- - This guide discusses how we should (and should not) speed up our code with inline assembly and explains how to write separate assembly routines that can be used within C.
- lujji: [Executing code from RAM on STM8](https://lujji.github.io/blog/executing-code-from-ram-on-stm8/)
- - A short article where we investigate how executing code from RAM can be achieved on STM8 with SDCC toolchain.
- lujji: [Bare metal programming: STM8](https://lujji.github.io/blog/bare-metal-programming-stm8/)
- - This article will cover developing for STM8 series of microcontrolles completely from scratch, without using any vendor-supplied libraries.

----------

- Klaasdc: [STM8S Projects](https://sites.google.com/site/klaasdc/stm8s-projects)
- - 16bit to BCD Conversion
- - A/D tacho conversion
- - Elevator codelock
- - RPM Counter

----------

- YouTube: [How to use STM8S Controller with Arduino IDE | SDUINO](https://www.youtube.com/watch?v=8CfD1d4Z_Vk)
- YouTube Playlist (42 videos): [STM8 Microcontroller Tutorials](https://www.youtube.com/playlist?list=PL-EErZRpDPIW2_hgHZEkgHINcSUKQS4LY)

----------

Arduino Core:
- https://tenbaht.github.io/sduino/
- https://github.com/tenbaht/sduino
- https://github.com/stm32duino/Arduino_Core_STM8

[The STM8S003 is almost identical to the STM8S103, the only difference is a smaller EEPROM area:](https://github.com/tenbaht/sduino/issues/90)

STM8S003F3: https://www.st.com/en/microcontrollers-microprocessors/stm8s003f3.html
- Data memory: 128 bytes true data EEPROM; endurance up to 100 k write/erase cycles 

STM8S103F3: https://www.st.com/en/microcontrollers-microprocessors/stm8s103f3.html
- Data memory: 640 byte true data EEPROM; endurance 300 kcycle 

-----------

- Library provided by ST:

https://www.st.com/en/embedded-software/stsw-stm8069.html


- ST documments:
- - DS7147 Value line, 16-MHz STM8S 8-bit MCU, 8-Kbyte Flash memory, 128-byte data EEPROM, 10-bit ADC, 3 timers, UART, SPI, I²C
- - AN3280 Displaying variable voltage on a bar of LEDs using STM8S-DISCOVERY
- - AN2860 EMC guidelines for STM8 microcontrollers
- - AN1181 Electrostatic discharge sensitivity measurement
- - AN2752 Getting started with STM8S and STM8AF microcontrollers
- - AN3208 Microstepping motor drive with STM8A and STM8S microcontrollers
- - TN1163 Description of WLCSP for microcontrollers and recommendations for its use
- - TN0189 STM8 bootloader frequently asked questions
- - UM1542 Cold thermostat kit based on AC switches and the STM8S003F3
- - UM1546 STEVAL-IHM037V1 remote fan speed controller
- - RM0016 STM8S Series and STM8AF Series 8-bit microcontrollers
- - PM0051 How to program STM8S and STM8A Flash program memory and data EEPROM
- - PM0044 STM8 CPU programming manual
- - ES0102 STM8S001J3, STM8S003xx, STM8S103xx and STM8S903xx device limitations
- - DN0005 A three phase induction motor drive using a V/F control
- - AN5183 Adjustable LED blinking speed using STM8 Nucleo-64 boards and STM8 Nucleo-32 boards
- - AN3143 Audio software codec for the STM8S
- - AN2737 Basic in-application programming example using the STM8 I²C and SPI peripherals
- - AN5181 Building a thermometer using the STM8 Nucleo-64 boards
- - AN5176 Displaying variable voltage on a bar of LEDs using STM8 Nucleo-64 boards
- - Other docs

https://www.st.com/en/microcontrollers-microprocessors/stm8s003f3.html#documentation


----------------

- This project uses STM8S003F3P6, on board W1209 - Thermostat (or timer):

https://github.com/rtek1000/W1209-firmware-modified

- This project (maybe) uses STM8S003F3P6, in a programmable LED controller:

(RF magic Controller 6803 IC 133 Modes for Dream Color Chasing 5050 RGB LED Strip)

https://github.com/rtek1000/RF_Magic_Controller_6803_IC

-----------

- STM8 eForth is an interactive Forth system for the STM8 family of highly reliable 8-bit MCUs with 16bit extensions and modern peripherals that are easier to master than those in 32bit µCs.
- - The STM8 eForth core is written in STM8 assembly using the SDCC tool chain. Combining Forth with C is supported.

https://github.com/TG9541/stm8ef

-----------

Note: This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE
