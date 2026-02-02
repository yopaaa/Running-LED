#include "../LedAnimations.h"

unsigned long last_random_pulse_time = 0;

void random_pulse(CRGB color) {
  if (millis() - last_random_pulse_time >= animation_delay) {
    if (random8() < 50) {
      leds[random16(ledCount)] = color;
    } else {
      leds[random16(ledCount)] = CRGB::Black;
    }
    FastLED.show();
    last_random_pulse_time = millis(); // Update waktu terakhir animasi
  }
}

