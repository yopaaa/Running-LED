#include "../LedAnimations.h"

void solid_color(CRGB color) {
    fill_solid(leds, NUM_LEDS, color);
    FastLED.show();
  }

