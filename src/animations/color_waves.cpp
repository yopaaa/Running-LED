#include "../LedAnimations.h"

unsigned long last_color_waves_time = 0;
static uint8_t wave = 0;


void color_waves(CRGB color) {
  if (millis() - last_color_waves_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = blend_colors(color, CRGB::Black, sin8(i * 4 + wave));
    }
    wave++;
    FastLED.show();
    last_color_waves_time = millis(); // Update waktu terakhir animasi
  }
}

