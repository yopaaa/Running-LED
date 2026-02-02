#include "../LedAnimations.h"

unsigned long last_breathing_time = 0;
static uint8_t brightness = 0;
static bool direction = true;

void breathing_light(CRGB color) {
  if (millis() - last_breathing_time >= animation_delay) {
    fill_solid(leds, ledCount, color.fadeLightBy(255 - brightness));
    FastLED.show();
    brightness += direction ? 1 : -1;
    if (brightness == 0 || brightness == 255) direction = !direction;
    last_breathing_time = millis(); // Update waktu terakhir animasi
  }
}

