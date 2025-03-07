const ws = new WebSocket("ws://" + window.location.host + "/ws");

ws.onmessage = function (event) {
  console.log("WebSocket Data:", event.data);
};

function toggleLED(led) {
  fetch("/api/leds/toggle", { method: "POST", body: new URLSearchParams({ led }) });
}
