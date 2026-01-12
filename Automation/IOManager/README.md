# IOManager
- Manages digital and PWM outputs for LEDs, buzzer, and RGB.

## Files
 - `IOManager.h` / `IOManager.cpp` — main IO control code
 - `example.cpp` — demonstrates LED, buzzer, and RGB usage

## Features
 - Controls two digital LEDs
 - Controls buzzer output
 - Sets RGB color with PWM (0-255)
 - Easy integration with other modules

## Configuration setting is available in config.h

## Usage
Include the header and config:
```cpp
#include "IOManager.h"
#include "config.h"

Initialize:
IOManager::init();

```

## Example snippets are provided