#ifndef LED_ANIMATIONS_H
#define LED_ANIMATIONS_H

#include <FastLED.h>

// Konstanta global
// extern const int ledCount; // Jumlah LED pada strip
// extern CRGB leds;        // Array LED
extern CRGB *leds;
extern uint16_t ledCount;
// extern unsigned long last_animation_time = 0; // Untuk melacak waktu terakhir animasi diperbarui
const unsigned long animation_delay = 50; // Delay default dalam milidetik

// Deklarasi fungsi animasi
void solid_color(CRGB color);
void color_wipe(CRGB color);
void rainbow_cycle();
void theater_chase(CRGB color);
void strobe_light(CRGB color);
void random_colors();
void fade_in_out(CRGB color);
void knight_rider();
void sparkle(CRGB color);
void gradient_fade(CRGB color1, CRGB color2);
void fire_effect();
void twinkle_stars();
void comet_tail();
void pulse_wave();
void confetti();
void rainbow_fade();
void color_bounce(CRGB color1, CRGB color2);
void color_wave(CRGB color);
void random_blink(CRGB color);
void color_chase(CRGB color);
void color_gradient(CRGB color1, CRGB color2);
void color_pulse(CRGB color);
void color_ripple(CRGB color);
void color_burst(CRGB color);
void color_sweep(CRGB color);
void fireworks();
void meteor_rain(CRGB color);
void lightning();
void color_shift();
void color_fade_out(CRGB color);
void rainbow_comet();
void color_waves(CRGB color);
void random_pulse(CRGB color);
void color_gradient_sweep(CRGB color1, CRGB color2);
void color_bounce_wave(CRGB color1, CRGB color2);
void color_spiral(CRGB color);
void color_explosion(CRGB color);
void color_ripple_wave(CRGB color);
void color_fade_in_out_wave(CRGB color);
void color_chase_rainbow();
void breathing_light(CRGB color);
void random_sparkles(CRGB color);
void color_bounce_rainbow();
void color_gradient_fade(CRGB color1, CRGB color2);
void color_wave_pulse(CRGB color);
void color_spiral_wave(CRGB color);
void color_explosion_wave(CRGB color);
void color_ripple_pulse(CRGB color);
void color_fade_in_out_spiral(CRGB color);
void color_chase_spiral(CRGB color);
void aurora_effect();
void rainbow_wave();
void chasing_dots();

extern CRGB blend_colors(CRGB color1, CRGB color2, uint8_t blend);
extern uint8_t heat[];
// Struktur untuk menyimpan nama dan fungsi animasi
typedef void (*AnimationFunction)(CRGB color1, CRGB color2);
struct Animation {
  const char* name;
  AnimationFunction func;
};

// Array animasi
extern Animation animations[];
extern AnimationFunction find_animation(const char* name);

#endif

