#include "../LedAnimations.h"

unsigned long last_fade_wave_time = 0;
static uint8_t brightness = 0;
static bool direction = true;

void color_fade_in_out_wave(CRGB color) {
  if (millis() - last_fade_wave_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color.fadeLightBy(255 - (brightness + sin8(i * 4)));
    }
    brightness += direction ? 1 : -1;
    if (brightness == 0 || brightness == 255) direction = !direction;
    FastLED.show();
    last_fade_wave_time = millis(); // Update waktu terakhir animasi
  }
}

