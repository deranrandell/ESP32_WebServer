#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <ESPAsyncWebServer.h>

AsyncWebSocket ws("/ws");

void notifyClients(String data)
{
    ws.textAll(data);
}

void setupWebSockets()
{
    ws.onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client,
                  AwsEventType type, void *arg, uint8_t *data, size_t len)
               {
        if (type == WS_EVT_CONNECT) {
            Serial.println("New WebSocket Client Connected");
        } });
    server.addHandler(&ws);
}

#endif
