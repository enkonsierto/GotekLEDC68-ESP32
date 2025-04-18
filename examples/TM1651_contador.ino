#include "TM1651.h"

#define CLK_PIN  22
#define DATA_PIN 21

TM1651 display(CLK_PIN, DATA_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("Starting TM1651 with ESP32...");
    
    display.displaySet(BRIGHT_TYPICAL);
    display.displayClear();
}

void loop() {
    static int count = 0;
    
    display.displayInteger(count);
    Serial.print("Displaying: ");
    Serial.println(count);

    count = (count + 1) % 1000;
    delay(1000);
}
