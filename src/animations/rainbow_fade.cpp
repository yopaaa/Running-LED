#include "../LedAnimations.h"

unsigned long last_rainbow_fade_time = 0;
uint8_t hue_rainbow_fade = 0;

void rainbow_fade() {
  if (millis() - last_rainbow_fade_time >= animation_delay) {
    fill_solid(leds, ledCount, CHSV(hue_rainbow_fade, 255, 255));
    hue_rainbow_fade++;
    FastLED.show();
    last_rainbow_fade_time = millis(); // Update waktu terakhir animasi
  }
}

