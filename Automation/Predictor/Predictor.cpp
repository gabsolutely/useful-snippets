// Predictor.cpp

#include "Predictor.h"
#include <Arduino.h>
#include <math.h> // for fabs
#include "config.h"

// linear regression based predictor (slope method)
struct RingBuffer {
    float* buf = nullptr;
    int len = 0;
    int idx = 0;
    bool full = false;

    // initialize ring buffer
    void init(int L) {
        len = (L >= PREDICTOR_MIN_WINDOW) ? L : PREDICTOR_MIN_WINDOW;
        if (buf) free(buf);
        buf = (float*) malloc(sizeof(float) * len);
        for (int i = 0; i < len; i++) buf[i] = 0;
        idx = 0;
        full = false;
    }

    // push value into ring buffer
    inline void push(float v) {
        buf[idx] = v;
        idx = (idx + 1) % len;
        if (idx == 0) full = true;
    }

    // get num of elements in buffer
    inline int count() const {
        return full ? len : idx;
    }

    // get element at position i (0 = oldest)
    inline float get(int i) const {
        return buf[(idx + i) % len];
    }
};

// ring buffers for each parameter
static RingBuffer tempBuf;
static RingBuffer humBuf;
static RingBuffer lightBuf;

//predict using linear regression (slope)
static float predictSlope(RingBuffer& rb, float current, int stepsAhead) {
    rb.push(current);
    int N = rb.count();
    if (N < 3) return current;

    // calculate sums for linear regression
    float sumX=0, sumY=0, sumXY=0, sumXX=0;
    for (int i = 0; i < N; i++) {
        float x = (float)i;
        float y = rb.get(i);
        sumX  += x;
        sumY  += y;
        sumXY += x * y;
        sumXX += x * x;
    }

    // calculate slope (m) and predict
    float denom = (N * sumXX - sumX * sumX);
    if (fabs(denom) < 1e-6) return current;
    float slope = (N * sumXY - sumX * sumY) / denom;
    float last = rb.get(N - 1);
    
    return last + slope * stepsAhead;
}

void Predictor::init(int window) {
    tempBuf.init(window);
    humBuf.init(window);
    lightBuf.init(window);
}

// predictors implementation
float Predictor::predictTemp(float t, int stepsAhead) {
    return predictSlope(tempBuf, t, stepsAhead);
}

float Predictor::predictHum(float h, int stepsAhead) {
    return predictSlope(humBuf, h, stepsAhead);
}

int Predictor::predictLight(int l, int stepsAhead) {
    return (int)predictSlope(lightBuf, (float)l, stepsAhead);
}
