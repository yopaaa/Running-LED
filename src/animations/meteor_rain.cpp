#include "../LedAnimations.h"

unsigned long last_meteor_rain_time = 0;
static uint8_t position = 0;
void meteor_rain(CRGB color) {
  if (millis() - last_meteor_rain_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    for (int i = 0; i < 5; i++) {
      leds[(position + i) % ledCount] = color;
    }
    position = (position + 1) % ledCount;
    fadeToBlackBy(leds, ledCount, 20);
    FastLED.show();
    last_meteor_rain_time = millis(); // Update waktu terakhir animasi
  }
}

