// AnomalyDetector.cpp

#include "AnomalyDetector.h"
#include <Arduino.h>
#include <math.h> // for sqrt and fabs
#include "config.h"

// buffers and variables
static float tBuf[ANOMALY_MAX_BUF];
static float hBuf[ANOMALY_MAX_BUF];
static float lBuf[ANOMALY_MAX_BUF];

static int N = ANOMALY_BUFFER_SIZE;
static int idx = 0;
static bool full = false;

void AnomalyDetector::init(int bufLen) {
    N = (bufLen >= 4 && bufLen <= ANOMALY_MAX_BUF) ? bufLen : ANOMALY_BUFFER_SIZE;
    idx = 0;
    full = false;

    for (int i = 0; i < N; i++) {
        tBuf[i] = 0;
        hBuf[i] = 0;
        lBuf[i] = 0;
    }
}

// update buffers with new readings
void AnomalyDetector::update(float t, float h, int l) {
    tBuf[idx] = t;
    hBuf[idx] = h;
    lBuf[idx] = l;

    idx++;
    if (idx >= N) {
        idx = 0;
        full = true;
    }
}

// helpers for mean and variance
static float mean(const float *arr, int count) {
    float s = 0;
    for (int i = 0; i < count; i++) s += arr[i];
    return s / count;
}

static float variance(const float *arr, int count, float m) {
    float v = 0;
    for (int i = 0; i < count; i++) {
        float d = arr[i] - m;
        v += d * d;
    }
    return v / count;
}

// Z-score deviations
float AnomalyDetector::tempDeviation(float temp) {
    int c = full ? N : idx;
    if (c < ANOMALY_MIN_SAMPLES) return 0;

    float m = mean(tBuf, c);
    float var = variance(tBuf, c, m);
    float sd = sqrt(var);
    if (sd < 0.0001f) sd = 0.0001f;

    return (temp - m) / sd;
}

float AnomalyDetector::humDeviation(float hum) {
    int c = full ? N : idx;
    if (c < ANOMALY_MIN_SAMPLES) return 0;

    float m = mean(hBuf, c);
    float var = variance(hBuf, c, m);
    float sd = sqrt(var);
    if (sd < 0.0001f) sd = 0.0001f;

    return (hum - m) / sd;
}

float AnomalyDetector::lightDeviation(int light) {
    int c = full ? N : idx;
    if (c < ANOMALY_MIN_SAMPLES) return 0;

    float m = mean(lBuf, c);
    float var = variance(lBuf, c, m);
    float sd = sqrt(var);
    if (sd < 1.0f) sd = 1.0f;

    return ((float)light - m) / sd;
}

// anomaly detection functions
bool AnomalyDetector::detectTemp(float temp) {
    return fabs(tempDeviation(temp)) > ANOMALY_Z_LIMIT;
}
bool AnomalyDetector::detectHum(float hum) {
    return fabs(humDeviation(hum)) > ANOMALY_Z_LIMIT;
}
bool AnomalyDetector::detectLight(int light) {
    return fabs(lightDeviation(light)) > ANOMALY_Z_LIMIT;
}
