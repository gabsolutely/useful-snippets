# DataCards
- Generic module to update data cards on a page by matching data keys to element IDs.

## Files
 - `DataCards.js` — core function to update card values based on passed data object
 - `example.js` — simple usage example

## Features
 - Data keys correspond to element IDs
 - Optional container to scope the update
 - Optional formatter function for value display

## Configuration setting is available in config.js

## Usage
```js
import { updateDataCards } from './DataCards.js';

const data = {
  tempVal: 22.5,
  humVal: '45 %',
  ...
};

updateDataCards(data, {
  container: '#yourContainer',
  formatValue: (value, key) => {
    // custom formatting logic here, fallback is toString
    return value !== undefined ? value.toString() : '—';
  }
});
```

## Example snippets are provided.