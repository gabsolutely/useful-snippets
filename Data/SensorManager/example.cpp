#include <Arduino.h>
#include "SensorManager.h"
#include "config.h" // Include configuration if needed

// CONFIGURATION (examples)
#define OBS_PIN     12
#define LIGHT_PIN   34
#define DHT_PIN     4
#define DHT_TYPE    DHT11
#define BUFFER_SIZE 10

void setup() {
    Serial.begin(115200);
    SensorManager::init();
}

void loop() {
    // read sensors
    float temp = SensorManager::readTemp();
    float hum  = SensorManager::readHumidity();
    int light  = SensorManager::readLight();
    int motion = SensorManager::readMotion();

    // print results
    Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C, ");
    Serial.print("Humidity: "); Serial.print(hum); Serial.print("%, ");
    Serial.print("Light: "); Serial.print(light); Serial.print(", ");
    Serial.print("Motion: "); Serial.println(motion);

    // store readings for averaging
    SensorManager::averageReadings(temp, hum, light);

    // print average readings
    Serial.print("Average Temp: "); Serial.println(SensorManager::readAverageTemp());
    Serial.print("Average Humidity: "); Serial.println(SensorManager::readAverageHumidity());
    Serial.print("Average Light: "); Serial.println(SensorManager::readAverageLight());

    delay(2000);
}
