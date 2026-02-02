#include "../LedAnimations.h"

unsigned long last_comet_time = 0;
static uint8_t position = 0;
void comet_tail() {
  if (millis() - last_comet_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    leds[position] = CRGB::White;
    for (int i = 1; i < 10; i++) {
      leds[(position + i) % NUM_LEDS] = CHSV(0, 0, 255 - (i * 25));
    }
    position = (position + 1) % NUM_LEDS;
    FastLED.show();
    last_comet_time = millis(); // Update waktu terakhir animasi
  }
}

