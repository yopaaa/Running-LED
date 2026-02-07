#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_random_blink_time = 0;

void random_blink(CRGB color) {
  if (millis() - last_random_blink_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(cfg.numLeds)] = color;
    } else {
      leds[random16(cfg.numLeds)] = CRGB::Black;
    }
    FastLED.show();
    last_random_blink_time = millis(); // Update waktu terakhir animasi
  }
}

