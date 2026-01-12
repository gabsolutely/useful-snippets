import { fetchData } from "./DataFetcher.js";

// Example usage of fetchData function
setInterval(async () => {
  const d = await fetchData();
  console.log(d);
}, 1000);
