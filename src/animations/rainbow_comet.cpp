#include "../LedAnimations.h"

unsigned long last_rainbow_comet_time = 0;
static uint8_t position = 0;
void rainbow_comet() {
  if (millis() - last_rainbow_comet_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    for (int i = 0; i < 10; i++) {
      leds[(position + i) % NUM_LEDS] = CHSV((position * 4) + (i * 10), 255, 255);
    }
    position = (position + 1) % NUM_LEDS;
    FastLED.show();
    last_rainbow_comet_time = millis(); // Update waktu terakhir animasi
  }
}

