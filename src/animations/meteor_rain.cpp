#include "../LedAnimations.h"

unsigned long last_meteor_rain_time = 0;
static uint8_t position = 0;
void meteor_rain(CRGB color) {
  if (millis() - last_meteor_rain_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    for (int i = 0; i < 5; i++) {
      leds[(position + i) % NUM_LEDS] = color;
    }
    position = (position + 1) % NUM_LEDS;
    fadeToBlackBy(leds, NUM_LEDS, 20);
    FastLED.show();
    last_meteor_rain_time = millis(); // Update waktu terakhir animasi
  }
}

