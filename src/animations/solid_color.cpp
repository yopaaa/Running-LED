#include "../LedAnimations.h"
#include "../Web.h"

void solid_color(CRGB color) {
    fill_solid(leds, cfg.numLeds, color);
    FastLED.show();
  }

