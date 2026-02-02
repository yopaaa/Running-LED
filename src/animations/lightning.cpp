#include "../LedAnimations.h"

unsigned long last_lightning_time = 0;

void lightning() {
  if (millis() - last_lightning_time >= animation_delay) {
    if (random8() < 10) {
      fill_solid(leds, NUM_LEDS, CRGB::White);
      FastLED.show();
      delay(random8(50, 200)); // Tetap gunakan delay kecil untuk efek kilatan
    }
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    last_lightning_time = millis(); // Update waktu terakhir animasi
  }
}

