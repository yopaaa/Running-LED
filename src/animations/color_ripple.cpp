#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_color_ripple_time = 0;
static uint8_t center = cfg.numLeds / 2;

void color_ripple(CRGB color) {
  if (millis() - last_color_ripple_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = blend_colors(color, CRGB::Black, abs(i - center) * 4);
    }
    center = (center + 1) % cfg.numLeds;
    FastLED.show();
    last_color_ripple_time = millis(); // Update waktu terakhir animasi
  }
}

