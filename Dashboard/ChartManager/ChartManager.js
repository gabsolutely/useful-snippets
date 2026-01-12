import { MAX_POINTS } from "./config.js";

// Assumes Chart.js is loaded globally
export function makeChart(ctx, label, color) {
  return new Chart(ctx, {
    type: "line",
    data: {
      labels: [],
      datasets: [{
        label,
        data: [],
        borderColor: color,
        borderWidth: 2,
        pointRadius: 2,
        tension: 0.25
      }]
    },
    options: {
      responsive: true,
      animation: false,
      scales: { x: { display:false } }
    }
  });
}

// Adds a new data point to the chart and trims old points if exceeding MAX_POINTS
export function pushTrim(chart, label, value) {
  chart.data.labels.push(label);
  chart.data.datasets[0].data.push(value);

  if (chart.data.labels.length > MAX_POINTS) {
    chart.data.labels.shift();
    chart.data.datasets[0].data.shift();
  }

  chart.update("none");
}
