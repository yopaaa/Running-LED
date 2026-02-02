#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

struct AppConfig {
    uint16_t numLeds = 36;
    uint8_t brightness = 128;
};

extern AppConfig cfg;

#endif
