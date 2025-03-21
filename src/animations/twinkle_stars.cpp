#include "../LedAnimations.h"

unsigned long last_twinkle_time = 0;

void twinkle_stars() {
  if (millis() - last_twinkle_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(NUM_LEDS)] = CRGB::White;
    }
    fadeToBlackBy(leds, NUM_LEDS, 10);
    FastLED.show();
    last_twinkle_time = millis(); // Update waktu terakhir animasi
  }
}

