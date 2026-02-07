#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_gradient_time = 0;
uint8_t blendf = 0;

void gradient_fade(CRGB color1, CRGB color2) {
  if (millis() - last_gradient_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = blend_colors(color1, color2, blendf);
    }
    blendf++;
    FastLED.show();
    last_gradient_time = millis(); // Update waktu terakhir animasi
  }
}

