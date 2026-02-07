#include "../LedAnimations.h"
#include "../Web.h"

unsigned long last_bounce_rainbow_time = 0;
static uint8_t pos1 = 0, pos2 = cfg.numLeds / 2;

void color_bounce_rainbow() {
  if (millis() - last_bounce_rainbow_time >= animation_delay) {
    fill_solid(leds, cfg.numLeds, CRGB::Black);
    leds[pos1] = CHSV(pos1 * 4, 255, 255);
    leds[pos2] = CHSV(pos2 * 4, 255, 255);
    pos1 = (pos1 + 1) % cfg.numLeds;
    pos2 = (pos2 + 1) % cfg.numLeds;
    FastLED.show();
    last_bounce_rainbow_time = millis(); // Update waktu terakhir animasi
  }
}

