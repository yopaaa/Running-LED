#include "../LedAnimations.h"

unsigned long last_chasing_dots_time = 0;
static uint8_t pos1 = 0, pos2 = ledCount / 2;

void chasing_dots() {
  if (millis() - last_chasing_dots_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    leds[pos1] = CRGB::Red;
    leds[pos2] = CRGB::Blue;
    pos1 = (pos1 + 1) % ledCount;
    pos2 = (pos2 + 1) % ledCount;
    FastLED.show();
    last_chasing_dots_time = millis(); // Update waktu terakhir animasi
  }
}

