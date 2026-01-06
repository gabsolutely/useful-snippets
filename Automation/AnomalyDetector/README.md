# AnomalyDetector
- Detects anomalies in temperature, humidity, and light readings using Z-score calculations.

## Files
 - `AnomalyDetector.h` / `AnomalyDetector.cpp` — main detection code
 - `example.cpp` — shows how to initialize, update, and detect anomalies

## Features
 - Maintains sliding buffers for recent readings
 - Computes Z-score deviations for temperature, humidity, and light
 - Flags readings exceeding configurable limits
 - Configurable buffer size, Z-limit, and minimum sample count
 - Configuration setting is available in config.h

## Configuration setting is available in config.h

## Usage
Include header and config:
```cpp
#include "AnomalyDetector.h"
#include "config.h"

Initialize with a buffer size (optional, default from config):
AnomalyDetector::init(ANOMALY_BUFFER_SIZE); // uses default buffer size from config.h

```

# Example snippets are provided.