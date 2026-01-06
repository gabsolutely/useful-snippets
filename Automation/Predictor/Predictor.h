// Predictor.h

#pragma once
#include "config.h"

class Predictor {
public:
  static void init(int window = PREDICTOR_WINDOW_SIZE);
  static float predictTemp(float currentTemp, int stepsAhead = TEMP_PREDICT_STEPS);
  static float predictHum(float currentHum, int stepsAhead = HUM_PREDICT_STEPS);
  static int predictLight(int currentLight, int stepsAhead = LIGHT_PREDICT_STEPS);
};