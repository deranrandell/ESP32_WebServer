#ifndef SECURITY_H
#define SECURITY_H

#include "jwt.h"

bool isAuthorized(AsyncWebServerRequest *request)
{
    if (!request->hasHeader("Authorization"))
        return false;

    String token = request->header("Authorization");
    JWT jwt;
    jwt.setHS256Secret(JWT_SECRET);
    return jwt.verify(token);
}

#endif
