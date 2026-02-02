#include "../LedAnimations.h"

unsigned long last_pulse_time = 0;
static uint8_t wave = 0;

void pulse_wave() {
  if (millis() - last_pulse_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      leds[i] = CHSV(wave + (i * 4), 255, sin8(i + wave));
    }
    wave++;
    FastLED.show();
    last_pulse_time = millis(); // Update waktu terakhir animasi
  }
}

