#include "../LedAnimations.h"

unsigned long last_explosion_wave_time = 0;
static uint8_t center = ledCount / 2;

void color_explosion_wave(CRGB color) {
  if (millis() - last_explosion_wave_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = blend_colors(color, CRGB::Black, abs(i - center) * 4);
    }
    center = (center + 1) % ledCount;
    FastLED.show();
    last_explosion_wave_time = millis(); // Update waktu terakhir animasi
  }
}

