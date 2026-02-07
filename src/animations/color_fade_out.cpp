#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_color_fade_out_time = 0;
static uint8_t position = 0;
void color_fade_out(CRGB color) {
  if (millis() - last_color_fade_out_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = blend_colors(color, CRGB::Black, abs(i - position) * 4);
    }
    position = (position + 1) % cfg.numLeds;
    FastLED.show();
    last_color_fade_out_time = millis(); // Update waktu terakhir animasi
  }
}

