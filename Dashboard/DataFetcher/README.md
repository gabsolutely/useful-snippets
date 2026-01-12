# DataFetcher
- Fetches sensor data from local ESP or cloud backend, with automatic fallback.

## Files
 - `DataFetcher.js` — fetch logic with cloud/local fallback
 - `example.js` — demo fetching and logging data

## Features
 - Automatic fallback if cloud API fails
 - Works in both local and cloud modes
 - Returns JSON data for dashboard consumption

## Configuration setting is available in config.js

Usage
```js
import { fetchData } from "./DataFetcher.js";

const data = await fetchData();
console.log("Temp:", data.temp, "Humidity:", data.humidity);
```

## Example snippets are provided.