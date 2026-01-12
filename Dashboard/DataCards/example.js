import { updateDataCards } from './DataCards.js';
import { DEFAULTS } from './config.js';

// Example data to demonstrate the DataCards functionality
const exampleData = {
  tempVal: 22.5,
  humVal: '45 %',
  lightVal: 120,
  actionVal: 'On',
  motionVal: 1,
  avgTemp: '21.8',
  avgHum: '44',
  avgLight: '115',
};

// Update the DataCards with the example data
updateDataCards(exampleData, { container: DEFAULTS.container });
