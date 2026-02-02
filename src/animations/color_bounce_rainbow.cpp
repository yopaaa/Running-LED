#include "../LedAnimations.h"

unsigned long last_bounce_rainbow_time = 0;
static uint8_t pos1 = 0, pos2 = NUM_LEDS / 2;

void color_bounce_rainbow() {
  if (millis() - last_bounce_rainbow_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    leds[pos1] = CHSV(pos1 * 4, 255, 255);
    leds[pos2] = CHSV(pos2 * 4, 255, 255);
    pos1 = (pos1 + 1) % NUM_LEDS;
    pos2 = (pos2 + 1) % NUM_LEDS;
    FastLED.show();
    last_bounce_rainbow_time = millis(); // Update waktu terakhir animasi
  }
}

