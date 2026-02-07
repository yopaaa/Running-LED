#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_fireworks_time = 0;

void fireworks() {
  if (millis() - last_fireworks_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(cfg.numLeds)] = CHSV(random8(), 255, 255);
    }
    fadeToBlackBy(leds, cfg.numLeds, 20);
    FastLED.show();
    last_fireworks_time = millis(); // Update waktu terakhir animasi
  }
}

