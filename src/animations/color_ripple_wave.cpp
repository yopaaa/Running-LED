#include "../LedAnimations.h"

unsigned long last_ripple_wave_time = 0;
static uint8_t wave = 0;


void color_ripple_wave(CRGB color) {
  if (millis() - last_ripple_wave_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = blend_colors(color, CRGB::Black, sin8(abs(i - ledCount / 2) * 4 + wave));
    }
    wave++;
    FastLED.show();
    last_ripple_wave_time = millis(); // Update waktu terakhir animasi
  }
}

