// Threshold_Automation.cpp

#include "Automation.h"
#include <Arduino.h>
#include "config.h"

void Automation::init(){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void Automation::evaluate(float temp, float hum, int light, int motion){
  bool alert = false;
  if (temp > TEMP_THRESHOLD) alert = true;
  if (hum > HUM_THRESHOLD) alert = true;

  // PLACEHOLDERS
  if (light < LIGHT_THRESHOLD) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (motion) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // buzzer when alert
  digitalWrite(LED_BUILTIN, alert ? HIGH : LOW);
}