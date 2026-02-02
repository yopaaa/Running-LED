#include "../LedAnimations.h"

unsigned long last_chase_spiral_time = 0;
static uint8_t position = 0;
void color_chase_spiral(CRGB color) {
  if (millis() - last_chase_spiral_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    leds[position] = CHSV(position * 4, 255, 255);
    position = (position + 1) % ledCount;
    FastLED.show();
    last_chase_spiral_time = millis(); // Update waktu terakhir animasi
  }
}

