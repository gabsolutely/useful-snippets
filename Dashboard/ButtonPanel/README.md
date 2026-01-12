# ButtonPanel (Generic)

Module to set up any group of buttons with a single, reusable callback.

## Files
 - `ButtonPanel.js` — main setup function with customizable container and callback
 - `example.js` — example usage showing how to handle button clicks

## Features
 - Works with any set of buttons, no specific IDs
 - Custom callback receives the clicked button element
 - Supports `data-*` attributes or inner text to determine values

## Configuration setting is available in config.js

## Usage
```js
import { setupButtonPanel } from './ButtonPanel.js';
import { DEFAULTS } from './config.js';

function handleButtonClick(btn) {
  const value = btn.dataset.value ?? btn.innerText;
  console.log('Button clicked:', value);
}

setupButtonPanel({
  containerSelector: DEFAULTS.containerSelector,
  buttonSelector: DEFAULTS.buttonSelector,
  onClick: handleButtonClick,
});
```

## Example snippets are provided.