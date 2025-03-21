#include "../LedAnimations.h"

unsigned long last_sparkles_time = 0;

void random_sparkles(CRGB color) {
  if (millis() - last_sparkles_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(NUM_LEDS)] = color;
    }
    fadeToBlackBy(leds, NUM_LEDS, 10);
    FastLED.show();
    last_sparkles_time = millis(); // Update waktu terakhir animasi
  }
}

