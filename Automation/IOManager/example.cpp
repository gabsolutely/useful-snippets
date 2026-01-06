#include <Arduino.h>
#include "IOManager.h"
#include "config.h"

void setup() {
    Serial.begin(115200);

    // initialize IOManager
    IOManager::init();
}

void loop() {
    // blink main LED
    IOManager::setLed(true);
    delay(500);
    IOManager::setLed(false);
    delay(500);

    // toggle second LED
    IOManager::setLed2(true);
    delay(250);
    IOManager::setLed2(false);
    delay(250);

    // buzzer beep
    IOManager::buzz(true);
    delay(100);
    IOManager::buzz(false);
    delay(100);

    // RGB color cycle (red -> green -> blue)
    IOManager::setRGBColor(255,0,0);
    delay(500);
    IOManager::setRGBColor(0,255,0);
    delay(500);
    IOManager::setRGBColor(0,0,255);
    delay(500);
    IOManager::setRGBColor(0,0,0); // off
    delay(500);
}
