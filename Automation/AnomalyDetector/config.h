// AnomalyDetector/config.h
#pragma once

// sliding buffer size for anomaly detection
#define ANOMALY_BUFFER_SIZE 30

// minimum number of samples before computing deviation
#define ANOMALY_MIN_SAMPLES 6

// Z-score limit to flag anomalies
#define ANOMALY_Z_LIMIT    3.0f

// maximum allowed buffer size
#define ANOMALY_MAX_BUF     60
