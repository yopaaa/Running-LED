#include "../LedAnimations.h"

unsigned long last_color_gradient_time = 0;
uint8_t blendd = 0;

void color_gradient(CRGB color1, CRGB color2) {
  if (millis() - last_color_gradient_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = blend_colors(color1, color2, map(i, 0, ledCount - 1, 0, blendd));
    }
    blendd++;
    FastLED.show();
    last_color_gradient_time = millis(); // Update waktu terakhir animasi
  }
}

