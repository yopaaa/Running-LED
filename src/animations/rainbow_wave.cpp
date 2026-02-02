#include "../LedAnimations.h"

unsigned long last_rainbow_wave_time = 0;
uint8_t hue_rainbow_wave = 0;

void rainbow_wave() {
  if (millis() - last_rainbow_wave_time >= animation_delay) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(hue_rainbow_wave + (i * 4), 255, 255); // Nilai hue berubah berdasarkan posisi LED
    }
    hue_rainbow_wave++; // Meningkatkan hue untuk menggeser warna
    FastLED.show();
    last_rainbow_wave_time = millis(); // Update waktu terakhir animasi
  }
}

