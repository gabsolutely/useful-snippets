import { MAX_LOG } from "./config.js";

// Adds a log message to the specified element with a timestamp
export function addLog(el, msg) {
  const t = new Date().toLocaleTimeString();
  el.innerText = `[${t}] ${msg}\n` + el.innerText;

  // Trim log if it exceeds MAX_LOG characters
  if (el.innerText.length > MAX_LOG) {
    el.innerText = el.innerText.slice(0, MAX_LOG);
  }
}
