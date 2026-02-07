#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_theater_chase_time = 0;
static bool reversee = false;

void theater_chase(CRGB color) {
  if (millis() - last_theater_chase_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = (i % 3 == 0) ? color : CRGB::Black;
    }
    FastLED.show();
    reversee = !reversee; // Toggle arah
    last_theater_chase_time = millis(); // Update waktu terakhir animasi
  }
}

