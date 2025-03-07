#ifndef STORAGE_H
#define STORAGE_H

#include "SPIFFS.h"

void initSPIFFS()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("SPIFFS Mount Failed!");
    }
    else
    {
        Serial.println("SPIFFS Initialized.");
    }
}

void saveData(const char *filename, const String &data)
{
    File file = SPIFFS.open(filename, FILE_WRITE);
    if (file)
    {
        file.print(data);
        file.close();
    }
}

String loadData(const char *filename)
{
    File file = SPIFFS.open(filename, FILE_READ);
    if (!file)
        return "{}"; // Return empty JSON if file not found
    String data = file.readString();
    file.close();
    return data;
}

#endif
