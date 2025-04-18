# Gotek LEDC68 3-digit Display Driver for ESP32

This library allows you to control 3-digit LED displays based on the **TM1651** chip, often found in modified Gotek drives. It is designed specifically for use with ESP32 microcontrollers.

Many of these displays are removed or replaced when users modify their Gotek drives, leaving perfectly functional TM1651 displays unused. This project gives them a new purpose by adapting an existing Arduino driver to work with ESP32 SoCs.

---

## Features

- Compatible with TM1651-based 3-digit LED displays
- Designed for ESP32 boards (using GPIOs for CLK and DIO)
- Supports numeric display and several alphanumeric characters
- Brightness control (8 levels)
- Decimal point support
- Simple integration and clean code

---

## Credits & Sources

This library is based on the original work by [coopzone-dc](https://github.com/coopzone-dc/GotekLEDC68), with prior contributions from Fred Chu and Detlef Giessmann.  
The code has been adapted and refactored to ensure compatibility with ESP32 microcontrollers.

---

## Pinout / Connections

Viewed from the rear of the display board:

[![LEDC68 Pinout](https://github.com/coopzone-dc/GotekLEDC68/blob/master/docs/LEDC68-pin.png)](https://github.com/enkonsierto/GotekLEDC68-ESP32/blob/main/docs/LEDC68-pin.png)

<pre>
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
</pre>
⚠️ Use current-limiting resistors if needed when running at 5V with ESP32.

---

## Getting Started

1. Clone this repository or download the files.
2. Include `TM1651.cpp` and `TM1651.h` in your ESP32 Arduino project.
3. Initialize and use the display:

```cpp
#include "TM1651.h"

TM1651 display(18, 19); // CLK on GPIO 18, DIO on GPIO 19

void setup() {
  display.displaySet(BRIGHT_TYPICAL); // Set brightness (0–7)
  display.displayInteger(123);        // Show number
}
```

---

## Examples

    TM1651_show_all_chars.ino
    Scrolls through all available characters and symbols.

    TM1651_brightness_level.ino.ino
    Demonstrates all brightness levels (0–7), showing corresponding number.

    TM1651_counter.ino
    A basic counter from 000 to 999 increasing 1 each second.
    
---

## Project Ideas

    Digital counters (people, laps, etc.)

    Simple clocks or timers

    Display for sensor readings

    User interface for MIDI or sound devices with ESP32

    Score counters.

---

## License

This library is released under the LGPL v2.1 license.
You are free to use, modify, and redistribute the code, provided that the same license and attribution are preserved.

Want to contribute or show your project using this library? Feel free to share it!
