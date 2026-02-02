#include "../LedAnimations.h"

void solid_color(CRGB color) {
    fill_solid(leds, ledCount, color);
    FastLED.show();
  }

