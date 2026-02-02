#include "../LedAnimations.h"

unsigned long last_wave_pulse_time = 0;
static uint8_t wave = 0;

static uint8_t brightness = 0;
static bool direction = true;

void color_wave_pulse(CRGB color) {
  if (millis() - last_wave_pulse_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = blend_colors(color, CRGB::Black, sin8(i * 4 + wave));
    }
    wave++;
    brightness += direction ? 1 : -1;
    if (brightness == 0 || brightness == 255) direction = !direction;
    FastLED.show();
    last_wave_pulse_time = millis(); // Update waktu terakhir animasi
  }
}

