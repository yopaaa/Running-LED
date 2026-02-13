#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>

// ===== STRUCT CONFIG =====
struct Config {
  uint8_t ledPin;
  uint8_t buttonPin;
  uint8_t brightness;
  uint16_t numLeds;
};

// ===== GLOBAL OBJECT =====
extern Config cfg;
extern Preferences prefs;
extern WebServer server;

// ===== FUNCTION DECLARATION =====
void loadConfig();
void saveConfig();

void setupWeb();

#endif
