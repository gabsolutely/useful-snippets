# ChartManager
- Handles Chart.js creation and rolling window data for real-time graphs.

## Files
 - `ChartManager.js` — chart creation and push/trim logic
 - `example.js` — demonstrates adding random data to a chart

## Features
 - Rolling window of fixed size for real-time charts
 - Configurable colors and data points
 - Simple API to push data to any chart

## Configuration setting is available in config.js

## Usage
```javascript
import { makeChart, pushTrim } from "./ChartManager.js";
import { COLORS } from "./config.js";

const tempChart = makeChart(document.getElementById("tempChart").getContext("2d"), "Temperature", COLORS.TEMP);
pushTrim(tempChart, "12:00", 25.2);
```

## Example snippets are provided.