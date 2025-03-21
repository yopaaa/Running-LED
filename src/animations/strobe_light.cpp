#include "../LedAnimations.h"

unsigned long last_strobe_time = 0;
bool strobe_state = false;

void strobe_light(CRGB color) {
  if (millis() - last_strobe_time >= animation_delay) {
    if (strobe_state) {
      fill_solid(leds, NUM_LEDS, color);
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::Black);
    }
    FastLED.show();
    strobe_state = !strobe_state; // Toggle state
    last_strobe_time = millis(); // Update waktu terakhir animasi
  }
}

