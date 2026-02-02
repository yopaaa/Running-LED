#include "../LedAnimations.h"

unsigned long last_rainbow_comet_time = 0;
static uint8_t position = 0;
void rainbow_comet() {
  if (millis() - last_rainbow_comet_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    for (int i = 0; i < 10; i++) {
      leds[(position + i) % ledCount] = CHSV((position * 4) + (i * 10), 255, 255);
    }
    position = (position + 1) % ledCount;
    FastLED.show();
    last_rainbow_comet_time = millis(); // Update waktu terakhir animasi
  }
}

