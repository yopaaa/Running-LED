#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_knight_rider_time = 0;
static uint8_t position = 0;
static bool direction = true;

void knight_rider() {
  if (millis() - last_knight_rider_time >= animation_delay) {
    fill_solid(leds, cfg.numLeds, CRGB::Black);
    leds[position] = CRGB::Red;
    FastLED.show();

    position += direction ? 1 : -1;
    if (position == 0 || position == cfg.numLeds - 1) direction = !direction;

    last_knight_rider_time = millis(); // Update waktu terakhir animasi
  }
}

