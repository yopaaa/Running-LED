#include "../LedAnimations.h"

unsigned long last_color_burst_time = 0;
static uint8_t position = 0;
void color_burst(CRGB color) {
  if (millis() - last_color_burst_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    for (int i = 0; i < 5; i++) {
      leds[(position + i) % ledCount] = color;
    }
    position = (position + 1) % ledCount;
    FastLED.show();
    last_color_burst_time = millis(); // Update waktu terakhir animasi
  }
}

