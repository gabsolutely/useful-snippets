// DataFetcher.js

// Module to fetch data from the server based on environment configuration
import { BASE_URL, IS_CLOUD } from "./config.js";

// Fetch data from the server
export async function fetchData() {
  if (IS_CLOUD) {
    try {
      return await (await fetch(BASE_URL + "/api/data", { cache:"no-store" })).json();
    } catch {
      return await (await fetch("/data")).json();
    }
  }
  return await (await fetch("/data", { cache:"no-store" })).json();
}
