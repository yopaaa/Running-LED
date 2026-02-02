#include "../LedAnimations.h"

unsigned long last_ripple_pulse_time = 0;
static uint8_t wave = 0;
static uint8_t brightness = 0;
static bool direction = true;

void color_ripple_pulse(CRGB color) {
  if (millis() - last_ripple_pulse_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = blend_colors(color, CRGB::Black, sin8(abs(i - ledCount / 2) * 4 + wave));
    }
    wave++;
    brightness += direction ? 1 : -1;
    if (brightness == 0 || brightness == 255) direction = !direction;
    FastLED.show();
    last_ripple_pulse_time = millis(); // Update waktu terakhir animasi
  }
}

