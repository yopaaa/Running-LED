#include "../LedAnimations.h"

unsigned long last_chase_rainbow_time = 0;
static uint8_t position = 0;
void color_chase_rainbow() {
  if (millis() - last_chase_rainbow_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    leds[position] = CHSV(position * 4, 255, 255);
    position = (position + 1) % NUM_LEDS;
    FastLED.show();
    last_chase_rainbow_time = millis(); // Update waktu terakhir animasi
  }
}

