// DataFetcher/config.js

// Example condition to determine cloud environment
export const IS_CLOUD = location.hostname.includes("railway"); 

// export const BASE_URL = IS_CLOUD
export const BASE_URL = IS_CLOUD
  ? "https://INSERT_YOUR_CLOUD_URL_HERE"
  : "";
