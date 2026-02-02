#include "../LedAnimations.h"

unsigned long last_color_bounce_time = 0;
static uint8_t pos1 = 0, pos2 = ledCount / 2;

void color_bounce(CRGB color1, CRGB color2) {
  if (millis() - last_color_bounce_time >= animation_delay) {
    fill_solid(leds, ledCount, CRGB::Black);
    leds[pos1] = color1;
    leds[pos2] = color2;
    pos1 = (pos1 + 1) % ledCount;
    pos2 = (pos2 + 1) % ledCount;
    FastLED.show();
    last_color_bounce_time = millis(); // Update waktu terakhir animasi
  }
}

