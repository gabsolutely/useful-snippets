// Predictor/config.h
#pragma once

// sliding window size
#define PREDICTOR_WINDOW_SIZE 20

// default prediction horizon (samples ahead)
#define TEMP_PREDICT_STEPS   1
#define HUM_PREDICT_STEPS    1
#define LIGHT_PREDICT_STEPS  1

// minimum window size
#define PREDICTOR_MIN_WINDOW 4