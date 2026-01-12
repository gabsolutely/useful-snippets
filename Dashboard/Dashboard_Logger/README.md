# Dashboard_Logger
- Prepend-based event logger for dashboard “Recent Events” display.

## Files
 - `Logger.js` — addLog function for logging messages
 - `example.js` — demo logging

## Features
 - Maintains recent events like the dashboard “Recent Events” area
 - Limits text length to prevent overflow
 - Simple integration with any DOM element

## Configuration setting is available in config.js

Usage
```javascript
import { addLog } from "./Logger.js";

const logArea = document.getElementById("logArea");
addLog(logArea, "System started");
addLog(logArea, "Temperature threshold exceeded");
```

## Example snippets are provided.