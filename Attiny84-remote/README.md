ATTiny84 Remote
================

A simple gamepad remote that uses an ATTiny84 chip, programmed with Arduino IDE.   
It has 6 buttons and 2 programmable LEDs.  
The ATTiny84 supports standard UART serial (output only) on pin 2 (PB0). You can use this to communicate with another device, for example a Raspberry Pi or Arduino Uno.   

###Programming the ATTiny84
There are a number of guides available on the internet for programming an ATTiny84, simplest way is using another arduino.   
I have been using this core http://code.google.com/p/arduino-tiny/   
Follow their instructions to install it into the arduino IDE and set up your arduino, then select ATTiny84 @ 8MHz and burn bootloader   
Next download my example program onto your ATTiny84, ```Attiny84_remote_serial.ino```   



###Use with Raspberry Pi
The Raspberry Pi support 3.3v UART only! Do not power the ATTiny84 with 5v when using it with the Raspberry Pi.   
You can easily power the board off the Raspberry Pis 3.3v GPIO pin (pin 1), then connect ground to a ground pin on the Raspberry Pi (pin 6)   
Finally, connect serial pins, pin 2 (PB0) on the ATTiny84 to pin 10 on the Raspberry Pi.   
To allow us to use the serial port on the Raspberry Pi, we must disable the kernel debug on it.   
A great script to do that can be found here https://github.com/lurch/rpi-serial-console   
   
You can now write a program to capture the incoming data, I have included an example, ```SerialTest.py```   


###Pins
A pin layout can be found below. It features the different numbering systems. The Arduino-Tiny core uses the outermost numbering system (PA1 = 9). What the pins are attached to is also shown.
```
 ATMEL ATTINY84 / ARDUINO   
   
                              +-\/-+   
                        VCC  1|    |14  GND   
Serial          (D 10)  PB0  2|    |13  AREF (D  0) 10         RDown   
              0 (D  9)  PB1  3|    |12  PA1  (D  1) 9          Up   
              1         PB3  4|    |11  PA2  (D  2) 8          Left   
     PWM      2 (D  8)  PB2  5|    |10  PA3  (D  3) 7          Down   
GLED PWM      3 (D  7)  PA7  6|    |9   PA4  (D  4) 6          Right   
RLED PWM      4 (D  6)  PA6  7|    |8   PA5  (D  5) 5      PWM RUp   
                              +----+   
                           
```
