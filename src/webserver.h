#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <ESPAsyncWebServer.h>
#include "routes.h"
#include "websocket.h"

extern AsyncWebServer server;

void setupWebServer()
{
    setupRoutes();
    setupWebSockets();
    server.begin();
}

#endif
