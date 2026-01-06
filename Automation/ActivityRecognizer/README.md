# ActivityRecognizer
- Detects activity based on a sliding window of motion sensor readings.

## Files
 - `ActivityRecognizer.h` / `ActivityRecognizer.cpp` — main detection code
 - `example.cpp` — demonstrates detecting activity with a motion sensor

## Features
 - Sliding window detection
 - Threshold: at least half of the window must be active
 - Simple API for integration with other modules

## Configuration setting is available in config.h

## Usage
Include the header:
```cpp
#include "ActivityRecognizer.h"
#include "config.h"

Initialize:
ActivityRecognizer recognizer(ACTIVITY_WINDOW_SIZE);

```

# Example snippets are provided.