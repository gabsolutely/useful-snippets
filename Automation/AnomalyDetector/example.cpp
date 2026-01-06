#include <Arduino.h>
#include "AnomalyDetector.h"
#include "config.h"

void setup() {
    Serial.begin(115200);

    // initialize anomaly detector
    AnomalyDetector::init(ANOMALY_BUFFER_SIZE);
}

void loop() {
    // example sensor values
    float temp = 25.5;
    float hum  = 50.0;
    int light  = 200;

    // update buffer
    AnomalyDetector::update(temp, hum, light);

    // check for anomalies
    if (AnomalyDetector::detectTemp(temp)) {
        Serial.println("Temperature anomaly detected!");
    }
    if (AnomalyDetector::detectHum(hum)) {
        Serial.println("Humidity anomaly detected!");
    }
    if (AnomalyDetector::detectLight(light)) {
        Serial.println("Light anomaly detected!");
    }

    delay(2000);
}
