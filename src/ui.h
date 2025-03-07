// If storing UI in PROGMEM, you can use the following code to serve the HTML file:

#ifndef UI_H
#define UI_H

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Web Server</title>
    <script>
        const ws = new WebSocket("ws://" + window.location.host + "/ws");

        ws.onmessage = function(event) {
            console.log("WebSocket Data:", event.data);
        };

        function toggleLED(led) {
            fetch('/api/leds/toggle', { method: 'POST', body: new URLSearchParams({ led }) });
        }
    </script>
</head>
<body>
    <h1>ESP32 Control Panel</h1>
    <button onclick="toggleLED(1)">Toggle LED 1</button>
    <button onclick="toggleLED(2)">Toggle LED 2</button>
</body>
</html>
)rawliteral";

#endif
