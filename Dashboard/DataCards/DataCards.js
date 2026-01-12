// DataCards.js
/**
 * Updates data cards with given values
 * @param {Object} data - Key-value pairs representing data labels and values
 * @param {Object} [options] - Optional config
 * @param {HTMLElement|String} [options.container=document] - Parent container to query inside
 * @param {function} [options.formatValue] - Function to format value display
 */

// Update Data Cards
export function updateDataCards(data, options = {}) {
  const container = typeof options.container === 'string' ? document.querySelector(options.container) : options.container || document;
  const formatValue = options.formatValue || ((val) => val === undefined ? '—' : val.toString());

  if (!container) {
    console.warn('Container not found for DataCards update.');
    return;
  }

  // Iterate over data entries and update corresponding elements
  Object.entries(data).forEach(([key, value]) => {
    const el = container.querySelector(`#${key}`);
    if (el) el.innerText = formatValue(value, key);
  });
}
