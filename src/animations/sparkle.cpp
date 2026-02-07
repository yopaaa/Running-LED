#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_sparkle_time = 0;

void sparkle(CRGB color) {
  if (millis() - last_sparkle_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(cfg.numLeds)] = color;
    }
    fadeToBlackBy(leds, cfg.numLeds, 10);
    FastLED.show();
    last_sparkle_time = millis(); // Update waktu terakhir animasi
  }
}

