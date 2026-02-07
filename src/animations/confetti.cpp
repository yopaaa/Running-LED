#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_confetti_time = 0;

void confetti() {
  if (millis() - last_confetti_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(cfg.numLeds)] = CHSV(random8(), 255, 255);
    }
    fadeToBlackBy(leds, cfg.numLeds, 10);
    FastLED.show();
    last_confetti_time = millis(); // Update waktu terakhir animasi
  }
}

