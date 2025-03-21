#include "../LedAnimations.h"

unsigned long last_color_chase_time = 0;
static uint8_t position = 0;
void color_chase(CRGB color) {
  if (millis() - last_color_chase_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    leds[position] = color;
    position = (position + 1) % NUM_LEDS;
    FastLED.show();
    last_color_chase_time = millis(); // Update waktu terakhir animasi
  }
}

