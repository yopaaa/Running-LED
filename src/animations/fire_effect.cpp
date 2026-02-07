#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_fire_time = 0;
// uint8_t heat[cfg.numLeds];

void fire_effect() {
  if (millis() - last_fire_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      heat[i] = qsub8(heat[i], random8(0, 10));
      leds[i] = HeatColor(heat[i]);
    }
    heat[random8(cfg.numLeds)] = 255;
    FastLED.show();
    last_fire_time = millis(); // Update waktu terakhir animasi
  }
}

