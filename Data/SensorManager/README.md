# SensorManager
- Manages reading sensors and calculating rolling averages.

## Files
 - `SensorManager.h` / `SensorManager.cpp` — main sensor code
 - `example.cpp` — shows how to initialize SensorManager, read sensors, and compute averages

## Features
 - Reads temperature, humidity, light, and motion
 - Maintains rolling averages for temperature, humidity, and light
 - Easy integration with other modules like Automation
 - Invalid sensor values is ignored in the average calculations

## Configuration settings is available in config.h

## Usage
Include the header and config:
```cpp
#include "SensorManager.h"
#include "config.h"

Initialize:
SensorManager::init();

```

## Example snippets are provided.