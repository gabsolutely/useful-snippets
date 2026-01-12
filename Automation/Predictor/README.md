# Predictor
- Provides linear regression-based predictions for temperature, humidity, and light using a sliding window.

## Files
 - `Predictor.h` / `Predictor.cpp` — main prediction logic
 - `example.cpp` — demonstrates how to initialize Predictor and get predictions

## Features
 - Uses ring buffers to keep recent sensor data for trend analysis
 - Predicts future values using slope-based linear regression
 - Configurable window size and prediction steps
 - Lightweight and easy to integrate with sensor modules
 - Configuration setting is available in config.h

## Configuration setting is available in config.h

## Usage
Include the header and config:
```cpp
#include "Predictor.h"
#include "config.h"

Initialize with a window size (optional, default from config):
Predictor::init();  // uses default window size from config.h

```

## Example snippets are provided.