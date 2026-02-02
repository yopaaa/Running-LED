#include "../LedAnimations.h"

unsigned long last_color_bounce_time = 0;
static uint8_t pos1 = 0, pos2 = NUM_LEDS / 2;

void color_bounce(CRGB color1, CRGB color2) {
  if (millis() - last_color_bounce_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    leds[pos1] = color1;
    leds[pos2] = color2;
    pos1 = (pos1 + 1) % NUM_LEDS;
    pos2 = (pos2 + 1) % NUM_LEDS;
    FastLED.show();
    last_color_bounce_time = millis(); // Update waktu terakhir animasi
  }
}

