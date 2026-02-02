#include "../LedAnimations.h"

unsigned long last_color_burst_time = 0;
static uint8_t position = 0;
void color_burst(CRGB color) {
  if (millis() - last_color_burst_time >= animation_delay) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    for (int i = 0; i < 5; i++) {
      leds[(position + i) % NUM_LEDS] = color;
    }
    position = (position + 1) % NUM_LEDS;
    FastLED.show();
    last_color_burst_time = millis(); // Update waktu terakhir animasi
  }
}

