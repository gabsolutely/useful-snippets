#include <Arduino.h>
#include "Predictor.h"
#include "config.h" // Include configuration if needed

void setup() {
    Serial.begin(115200);

    // initialize predictor with window size
    Predictor::init(PREDICTOR_WINDOW_SIZE);
}

void loop() {
    // placeholder sensor data
    float temp = 25.4;
    float hum  = 49.2;
    int light  = 210;

    // predict next values
    float tempPred = Predictor::predictTemp(temp, TEMP_PREDICT_STEPS);
    float humPred = Predictor::predictHum(hum, HUM_PREDICT_STEPS);
    int lightPred = Predictor::predictLight(light, LIGHT_PREDICT_STEPS);

    Serial.print("Temp: "); Serial.print(temp);
    Serial.print(" -> "); Serial.println(tempPred);

    Serial.print("Hum: "); Serial.print(hum);
    Serial.print(" -> "); Serial.println(humPred);

    Serial.print("Light: "); Serial.print(light);
    Serial.print(" -> "); Serial.println(lightPred);

    delay(2000);
}
