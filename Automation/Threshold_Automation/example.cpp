#include <Arduino.h>
#include "Automation.h"
#include "config.h"

void setup() {
    Serial.begin(115200);
    Automation::init();
}

void loop() {
    float temp = 32.5;   // placeholder sensor readings
    float hum  = 80.0;
    int light  = 1000;
    int motion = digitalRead(4); // motion sensor on pin 4

    // Evaluate automation conditions
    Automation::evaluate(temp, hum, light, motion);

    Serial.print("Temp: "); Serial.print(temp);
    Serial.print(" Hum: "); Serial.print(hum);
    Serial.print(" Light: "); Serial.print(light);
    Serial.print(" Motion: "); Serial.println(motion);

    delay(2000);
}
