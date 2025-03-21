#include "../LedAnimations.h"

unsigned long last_fire_time = 0;
// uint8_t heat[NUM_LEDS];

void fire_effect() {
  if (millis() - last_fire_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      heat[i] = qsub8(heat[i], random8(0, 10));
      leds[i] = HeatColor(heat[i]);
    }
    heat[random8(NUM_LEDS)] = 255;
    FastLED.show();
    last_fire_time = millis(); // Update waktu terakhir animasi
  }
}

