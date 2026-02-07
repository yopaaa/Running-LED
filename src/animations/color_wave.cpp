#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_color_wave_time = 0;
static uint8_t wave = 0;


void color_wave(CRGB color) {
  if (millis() - last_color_wave_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = blend_colors(color, CRGB::Black, sin8(i * 4 + wave));
    }
    wave++;
    FastLED.show();
    last_color_wave_time = millis(); // Update waktu terakhir animasi
  }
}

