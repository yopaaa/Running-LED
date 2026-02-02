#include "../LedAnimations.h"

unsigned long last_color_shift_time = 0;
uint8_t hue_color_shift = 0;

void color_shift() {
  if (millis() - last_color_shift_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = CHSV(hue_color_shift + random8(30), 255, 255);
    }
    hue_color_shift++;
    FastLED.show();
    last_color_shift_time = millis(); // Update waktu terakhir animasi
  }
}

