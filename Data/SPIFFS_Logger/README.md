# SPIFFS_Logger
- Manages SPIFFS logging and builds JSON payloads.

## Files
 - `Logger.h` / `Logger.cpp` — main logging code
 - `example.cpp` — demonstrates logging to CSV and building payloads

## Features
 - Clears file contents on boot if configured
 - Logs sensor readings to CSV on SPIFFS
 - Automatically creates CSV header
 - Limits file size to avoid overflow
 - Builds JSON payloads for cloud use

## Configuration settings is available in config.h

## Usage
Include the header and config:
```cpp
#include "Logger.h"
#include "config.h" 

Initialize:
Logger::init();

```

# Example snippets are provided.