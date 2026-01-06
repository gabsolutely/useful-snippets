#include <Arduino.h>
#include "Logger.h"
#include "config.h" // Include configuration if needed

void setup() {
    Serial.begin(115200);
    // initialize logger (SPIFFS, CSV file, Clear on boot if configured, etc)
    Logger::init();
}

void loop() {
    // placeholder sensor data
    float temp = 25.5;
    float avgTemp = 26.0;
    float hum = 50.0;
    float avgHum = 48.5;
    int light = 200;
    int avgLight = 180;
    int motion = 1;
    int action = 2;

    // append to log
    Logger::append(temp, avgTemp, hum, avgHum, light, avgLight, motion, action);

    // build and print payload
    char payload[128];
    Logger::buildPayload(temp, avgTemp, hum, avgHum, light, avgLight, motion, action, payload, sizeof(payload));
    Serial.println(payload);

    delay(5000);
}
