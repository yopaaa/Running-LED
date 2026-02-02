#include "../LedAnimations.h"

unsigned long last_random_colors_time = 0;

void random_colors() {
  if (millis() - last_random_colors_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = CHSV(random8(), 255, 255);
    }
    FastLED.show();
    last_random_colors_time = millis(); // Update waktu terakhir animasi
  }
}

