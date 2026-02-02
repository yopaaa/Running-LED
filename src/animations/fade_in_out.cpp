#include "../LedAnimations.h"

unsigned long last_fade_time = 0;
static uint8_t brightness = 0;
bool fade_direction = true;

void fade_in_out(CRGB color) {
  if (millis() - last_fade_time >= animation_delay) {
    fill_solid(leds, ledCount, color.fadeLightBy(255 - brightness));
    FastLED.show();

    if (fade_direction) {
      brightness++;
      if (brightness >= 255) fade_direction = false;
    } else {
      brightness--;
      if (brightness == 0) fade_direction = true;
    }

    last_fade_time = millis(); // Update waktu terakhir animasi
  }
}

