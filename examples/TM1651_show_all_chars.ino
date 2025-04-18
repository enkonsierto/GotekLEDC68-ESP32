#include <Arduino.h>
#include "TM1651.h"

#define CLK_PIN  18  // Adjust according to your connection
#define DATA_PIN 19  // Adjust according to your connection

TM1651 display(CLK_PIN, DATA_PIN);
int charIndex = 0;
bool dpEnabled = false;

static int8_t NumTab[] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, // Numbers 0-9
  0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,  // Letters A-F
  0x00, 0x63, 0x5C, 0x01, 0x40, 0x08   // Special characters
};
const int totalChars = sizeof(NumTab) / sizeof(NumTab[0]);

void setup() {
  display.displaySet(BRIGHT_TYPICAL);
}

void loop() {
  updateDisplay();
  delay(1000);  // Change every second
  charIndex = (charIndex + 1) % totalChars;  // Move to the next character
  dpEnabled = !dpEnabled;  // Toggle the decimal point
}

void updateDisplay() {
  display.displayClear();
  display.displayNum(1, charIndex); // Displays the character in the central position
  if (dpEnabled) {
    display.displayDP(0x08); // Turns on the decimal point
  }
}
