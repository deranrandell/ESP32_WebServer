# ESP32 Web Server with WebSockets and SPIFFS

This project creates a web server running on an ESP32, allowing users to control LEDs via a web interface. The server serves HTML, CSS, and JavaScript files stored in SPIFFS (Serial Peripheral Interface Flash File System), and uses WebSockets for real-time communication between the ESP32 and the client. The configuration for WiFi, JWT secret, and other settings are loaded from a JSON file stored on SPIFFS.

## Features
- **Web Interface**: A simple control panel to toggle LEDs on the ESP32.
- **WebSockets**: Real-time communication to send and receive data between the client and the ESP32.
- **SPIFFS Storage**: Stores configuration files and static assets (HTML, CSS, JavaScript) on the ESP32.
- **Security**: JWT-based authentication to ensure secure access to API routes.
- **WiFi Connection**: Connects to a WiFi network using credentials stored in a configuration file.

## Components
- **ESP32**: A low-cost, low-power microcontroller with built-in WiFi.
- **Web Server**: Built using the `ESPAsyncWebServer` library.
- **WebSockets**: For real-time, bi-directional communication between the ESP32 and web client.
- **SPIFFS**: File system for storing configuration and static files on the ESP32.

## Requirements
- **Hardware**:
  - ESP32 development board.
  - LEDs connected to GPIO pins (e.g., LED 1 and LED 2).
- **Software**:
  - [PlatformIO](https://platformio.org/) (for managing libraries and uploading code).
  - [Arduino IDE](https://www.arduino.cc/en/software) (optional for basic testing).

## Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/ESP32_WebServer.git
   cd ESP32_WebServer
Install Dependencies:
Ensure you have the following libraries installed via PlatformIO:

WiFi
ESPAsyncWebServer
ArduinoJson
FS
SPIFFS
AsyncTCP
This is automatically handled by PlatformIO via the lib_deps section in platformio.ini.

Configure WiFi and Settings: The ESP32 connects to your WiFi network using credentials stored in a JSON configuration file (/data/config.json). The settings include:

WiFi SSID and password
Server port
JWT secret
OTA (Over-the-Air) updates enabled/disabled
Example config.json:

json
Copy
Edit
{
    "wifi_ssid": "MyWiFi",
    "wifi_password": "SecurePassword",
    "server_port": 80,
    "jwt_secret": "SuperSecureSecret",
    "ota_enabled": true
}
The configuration is loaded from SPIFFS during startup using loadConfig() in config.h.
Upload the Code:

Connect the ESP32 to your computer.
Open the project in PlatformIO.
Upload the code to the ESP32 via the platformio.ini configuration.
Upload Static Files to SPIFFS:

Place your static files (HTML, CSS, JS) into the data/ folder in your project.
Use PlatformIO's "Upload File System Image" option to upload these files to SPIFFS.
Access the Web Server:

Once the ESP32 is running, open a browser and visit the IP address of the ESP32.
The dashboard will load with buttons to toggle LEDs and view WebSocket messages.
File Structure
plaintext
Copy
Edit
ESP32_WebServer/
├── data/
│   ├── config.json        # WiFi and JWT settings
│   ├── index.html         # Main HTML interface
│   ├── script.js          # JavaScript for WebSocket and button actions
│   ├── style.css          # CSS for styling the UI
├── src/
│   ├── config.h           # Configuration loading and settings
│   ├── main.cpp           # Main application code (setup/loop)
│   ├── routes.h           # API route handlers
│   ├── security.h         # JWT authentication
│   ├── storage.h          # SPIFFS storage functions
│   ├── ui.h               # UI content served from PROGMEM
│   ├── websocket.h        # WebSocket setup and notifications
│   └── webserver.h        # Web server setup
├── platformio.ini         # PlatformIO configuration file
└── README.md              # Project documentation
Web Interface
The web interface contains:

Buttons to toggle LEDs connected to the ESP32.
WebSocket connection to receive real-time updates.
The WebSocket connection is established in the browser, and any data sent from the server will be logged in the browser console.

Security
JWT Authentication is required to access certain API routes, such as toggling LEDs.
The JWT secret is stored securely in config.json and is used to verify the token sent with API requests.
Unauthorized requests will be rejected with a 403 error.
OTA Updates
OTA (Over-the-Air) updates are supported. If enabled in the configuration (ota_enabled: true), the device can receive firmware updates over WiFi.

License
This project is licensed under the MIT License - see the LICENSE file for details.