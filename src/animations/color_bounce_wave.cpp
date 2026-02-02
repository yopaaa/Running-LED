#include "../LedAnimations.h"

unsigned long last_bounce_wave_time = 0;
uint8_t wave1 = 0, wave2 = 0;

void color_bounce_wave(CRGB color1, CRGB color2) {
  if (millis() - last_bounce_wave_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = blend_colors(color1, color2, sin8(i * 4 + wave1) + sin8(i * 4 + wave2));
    }
    wave1++;
    wave2--;
    FastLED.show();
    last_bounce_wave_time = millis(); // Update waktu terakhir animasi
  }
}

