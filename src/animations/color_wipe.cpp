#include "../LedAnimations.h"

unsigned long last_color_wipe_time = 0;
uint8_t wipe_position = 0;

void color_wipe(CRGB color) {
  if (millis() - last_color_wipe_time >= animation_delay) {
    if (wipe_position < ledCount) {
      leds[wipe_position] = color;
      FastLED.show();
      wipe_position++;
    } else {
      wipe_position = 0; // Reset posisi setelah selesai
    }
    last_color_wipe_time = millis(); // Update waktu terakhir animasi
  }
}

