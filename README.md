Gotek 3-digit LED display driver for ESP32

This is an ESP32 library for using re-purposed LEDC68 3 digit LED displays from GoTek Drives.

This repository is based on the work of coopzone-dc [https://github.com/coopzone-dc/GotekLEDC68].

This repository adapts the original driver for Arduino to work with ESP32 SOCs.
there are a lot of 3 digit LCDs TM1651 chip that are changed for another ones to show text and other useful information with the Gotek. Seeing that there are a lot of new LCDs wituot use, I decided to search a driver to give them a new life, I couldn't find one for ESP32 (the SOC I'm using at this moment), but I found the mentioned for Arduino and I thought to adapt the code.
For more information go to the original repository.

Connections to the board are (viewed from the rear):



!----------------------------!
! x1 x3  c                   !
!        c                   !
! x2 x4  c                   !
!                            !
! !--------|                 !
! ! TM1651 !                 !
! !--------|                 !
!----------------------------!

x1=clk
x2=dio
x3=GND
x4=+5v (3.3-5v)
