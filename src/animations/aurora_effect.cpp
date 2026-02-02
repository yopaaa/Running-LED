#include "../LedAnimations.h"

unsigned long last_aurora_time = 0;
uint8_t color_picker = 0;

void aurora_effect() {
  if (millis() - last_aurora_time >= animation_delay) {
    for (int i = 0; i < ledCount; i++) {
      if (random8() < 50) { // Probabilitas rendah untuk memilih biru atau merah
        leds[i] = CHSV(color_picker, 255, 255); // Menggunakan warna HSV untuk transisi halus
      } else {
        leds[i] = CHSV(96, 255, random8(128, 255)); // Hijau dan variasi terang
      }
    }
    color_picker++;
    FastLED.show();
    last_aurora_time = millis(); // Update waktu terakhir animasi
  }
}

