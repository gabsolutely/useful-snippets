# Threshold_Automation
- Simple module to trigger actions based on sensor thresholds.

## Files
 - `Threshold_Automation.h` / `Threshold_Automation.cpp` — main automation code
 - `example.cpp` — demonstrates using the automation module

## Features
 - Turns LED (or buzzer) based on temperature, humidity, light, and motion
 - Thresholds are configurable in `config.h`
 - Simple and extendable for home automation or alerts

## Configuration setting is available in config.h

## Usage
Include the header:
```cpp
#include "Automation.h"
#include "config.h"

Initialize:
Threshold_Automation::init();

```

# Example snippets are provided.