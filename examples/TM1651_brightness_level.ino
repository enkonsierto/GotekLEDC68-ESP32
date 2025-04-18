#include "TM1651.h"

#define CLK_PIN  22
#define DATA_PIN 21

TM1651 display(CLK_PIN, DATA_PIN);
int brightnessLevel = BRIGHT_DARKEST;

static int8_t NumTab[] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
  0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,
  0x00, 0x63, 0x5C, 0x01, 0x40, 0x08
};
const int totalChars = sizeof(NumTab) / sizeof(NumTab[0]);

void setup() {
  display.displaySet(brightnessLevel);
}

void loop() {
  for (brightnessLevel = BRIGHT_DARKEST; brightnessLevel <= BRIGHTEST; brightnessLevel++) {
    display.displaySet(brightnessLevel);
    display.displayClear();
    display.displayInteger(brightnessLevel);
    delay(1000);
  }
}
