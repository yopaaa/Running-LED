#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_gradient_fade_time = 0;
uint8_t blende = 0;

void color_gradient_fade(CRGB color1, CRGB color2) {
  if (millis() - last_gradient_fade_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = blend_colors(color1, color2, map(i, 0, cfg.numLeds - 1, 0, blende));
    }
    blende++;
    FastLED.show();
    last_gradient_fade_time = millis(); // Update waktu terakhir animasi
  }
}

