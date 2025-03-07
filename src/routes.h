#ifndef ROUTES_H
#define ROUTES_H

#include <ESPAsyncWebServer.h>
#include "storage.h"
#include "security.h"

extern AsyncWebServer server;

void setupRoutes()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send_P(200, "text/html", index_html); });

    server.on("/api/leds/toggle", HTTP_POST, [](AsyncWebServerRequest *request)
              {
        if (!isAuthorized(request)) {
            request->send(403, "application/json", "{\"error\": \"Unauthorized\"}");
            return;
        }
        int led = request->getParam("led", true)->value().toInt();
        toggleLED(led);
        request->send(200, "application/json", "{\"status\": \"ok\"}"); });
}

#endif
