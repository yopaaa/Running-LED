#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_color_sweep_time = 0;
static uint8_t position = 0;
void color_sweep(CRGB color) {
  if (millis() - last_color_sweep_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = (i == position) ? color : CRGB::Black;
    }
    position = (position + 1) % cfg.numLeds;
    FastLED.show();
    last_color_sweep_time = millis(); // Update waktu terakhir animasi
  }
}

