import { setupButtonPanel } from './ButtonPanel.js';
import { DEFAULTS } from './config.js';

// Example callback, prints button label or dataset value
function handleButtonClick(btn) {
  const value = btn.dataset.value ?? btn.innerText;
  console.log('Button clicked:', value);
  // additional logic can be added here
}

// Initialize the ButtonPanel with default selectors and the click handler
setupButtonPanel({
  containerSelector: DEFAULTS.containerSelector,
  buttonSelector: DEFAULTS.buttonSelector,
  onClick: handleButtonClick,
});
