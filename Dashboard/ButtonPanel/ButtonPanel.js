/**
 * Sets up buttons with customizable selectors and callbacks
 *
 * @param {Object} options
 * @param {string} [options.containerSelector] - Selector for container holding buttons
 * @param {string} [options.buttonSelector='button'] - Selector for buttons inside container
 * @param {function} [options.onClick] - Callback receiving clicked button element
 */

// Setup function for button panel
export function setupButtonPanel({
  // Default parameters
  containerSelector,
  buttonSelector = 'button',
  onClick = (btn) => console.log('Button clicked:', btn),
} = {}) {
  if (!containerSelector) {
    console.warn('No containerSelector provided for ButtonPanel.');
    return;
  }

  // Query buttons and attach click event listeners
  const container = document.querySelector(containerSelector);
  if (!container) {
    console.warn('Container not found for ButtonPanel:', containerSelector);
    return;
  }

  container.querySelectorAll(buttonSelector).forEach(btn => {
    btn.addEventListener('click', () => onClick(btn));
  });
}
