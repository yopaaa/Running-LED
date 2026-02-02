#include "../LedAnimations.h"

unsigned long last_spiral_wave_time = 0;
static uint8_t offset = 0;

void color_spiral_wave(CRGB color) {
  if (millis() - last_spiral_wave_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = blend_colors(color, CRGB::Black, sin8((i + offset) * 4));
    }
    offset++;
    FastLED.show();
    last_spiral_wave_time = millis(); // Update waktu terakhir animasi
  }
}

