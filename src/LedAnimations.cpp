#include "LedAnimations.h"

// uint8_t heat[60];

CRGB blend_colors(CRGB color1, CRGB color2, uint8_t blend) {
  uint8_t inverse_blend = 255 - blend;
  return CRGB(
    (color1.r * inverse_blend + color2.r * blend) >> 8,
    (color1.g * inverse_blend + color2.g * blend) >> 8,
    (color1.b * inverse_blend + color2.b * blend) >> 8
  );
}


AnimationFunction find_animation(const char* name) {
  for (int i = 0; animations[i].name != nullptr; i++) {
    if (strcmp(animations[i].name, name) == 0) {
      return animations[i].func;
    }
  }
  return nullptr; // Animasi tidak ditemukan
}


















