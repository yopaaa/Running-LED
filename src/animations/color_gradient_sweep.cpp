#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_gradient_sweep_time = 0;
static uint8_t offset = 0;

void color_gradient_sweep(CRGB color1, CRGB color2) {
  if (millis() - last_gradient_sweep_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = blend_colors(color1, color2, map((i + offset) % cfg.numLeds, 0, cfg.numLeds - 1, 0, 255));
    }
    offset++;
    FastLED.show();
    last_gradient_sweep_time = millis(); // Update waktu terakhir animasi
  }
}

