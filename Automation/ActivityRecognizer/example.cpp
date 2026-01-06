#include <Arduino.h>
#include "ActivityRecognizer.h"
#include "config.h"

ActivityRecognizer recognizer(ACTIVITY_WINDOW_SIZE);

void setup() {
    Serial.begin(115200);
}

void loop() {
    int motion = digitalRead(4); // assuming motion sensor on pin 4
    ActivityRecognizer::Activity act = recognizer.detect(motion);

    if (act == ActivityRecognizer::ACTIVITY) {
        Serial.println("Activity detected!");
    } else {
        Serial.println("No activity");
    }

    delay(500);
}