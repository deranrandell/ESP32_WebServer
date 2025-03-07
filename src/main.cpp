#include <Arduino.h>
#include <WiFi.h>
#include "config.h"
#include "webserver.h"
#include "storage.h"

void setup()
{
    Serial.begin(115200);
    connectWiFi();
    initSPIFFS();
    setupWebServer();
}

void loop()
{
    // If using AsyncWebServer, loop is empty
}
