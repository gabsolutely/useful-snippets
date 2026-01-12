import { makeChart, pushTrim } from "./ChartManager.js";
import { COLORS } from "./config.js";

// Create a temperature chart
const chart = makeChart(
  document.getElementById("tempChart").getContext("2d"),
  "Temperature",
  COLORS.TEMP
);

// Simulate incoming temperature data every second
setInterval(() => {
  pushTrim(chart, new Date().toLocaleTimeString(), Math.random() * 30);
}, 1000);
