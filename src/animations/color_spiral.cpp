#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_spiral_time = 0;
static uint8_t offset = 0;

void color_spiral(CRGB color) {
  if (millis() - last_spiral_time >= animation_delay) {
    for (int i = 0; i < cfg.numLeds; i++) {
      leds[i] = CHSV((offset + i * 4) % 255, 255, 255);
    }
    offset++;
    FastLED.show();
    last_spiral_time = millis(); // Update waktu terakhir animasi
  }
}

