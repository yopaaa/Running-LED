#include "../LedAnimations.h"

unsigned long last_comet_time = 0;
static uint8_t position = 0;
void comet_tail() {
  if (millis() - last_comet_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    leds[position] = CRGB::White;
    for (int i = 1; i < 10; i++) {
      leds[(position + i) % ledCount] = CHSV(0, 0, 255 - (i * 25));
    }
    position = (position + 1) % ledCount;
    FastLED.show();
    last_comet_time = millis(); // Update waktu terakhir animasi
  }
}

