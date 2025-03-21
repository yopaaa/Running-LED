#include "../LedAnimations.h"

unsigned long last_rainbow_cycle_time = 0;
uint8_t hue_rainbow_cycle = 0;

void rainbow_cycle() {
  if (millis() - last_rainbow_cycle_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV((hue_rainbow_cycle + i * 4), 255, 255);
    }
    hue_rainbow_cycle++;
    FastLED.show();
    last_rainbow_cycle_time = millis(); // Update waktu terakhir animasi
  }
}

