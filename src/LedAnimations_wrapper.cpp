#include "LedAnimations.h"


// Wrapper untuk solid_color
void solid_color_wrapper(CRGB color1, CRGB color2)
{
    solid_color(color1); // Menggunakan color1
    
}

// Wrapper untuk color_wipe
void color_wipe_wrapper(CRGB color1, CRGB color2)
{
    color_wipe(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk rainbow_cycle
void rainbow_cycle_wrapper(CRGB color1, CRGB color2)
{
    rainbow_cycle(); // Mengabaikan color1 dan color2
}

// Wrapper untuk theater_chase
void theater_chase_wrapper(CRGB color1, CRGB color2)
{
    theater_chase(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk strobe_light
void strobe_light_wrapper(CRGB color1, CRGB color2)
{
    strobe_light(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk random_colors
void random_colors_wrapper(CRGB color1, CRGB color2)
{
    random_colors(); // Mengabaikan semua parameter
    
}

// Wrapper untuk fade_in_out
void fade_in_out_wrapper(CRGB color1, CRGB color2)
{
    fade_in_out(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk knight_rider
void knight_rider_wrapper(CRGB color1, CRGB color2)
{
    knight_rider(); // Mengabaikan color1 dan color2
}

// Wrapper untuk sparkle
void sparkle_wrapper(CRGB color1, CRGB color2)
{
    sparkle(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk gradient_fade
void gradient_fade_wrapper(CRGB color1, CRGB color2)
{
    gradient_fade(color1, color2); // Menggunakan color1, color2, dan delay_ms
}

// Wrapper untuk fire_effect
void fire_effect_wrapper(CRGB color1, CRGB color2)
{
    fire_effect(); // Mengabaikan semua parameter
    
}

// Wrapper untuk twinkle_stars
void twinkle_stars_wrapper(CRGB color1, CRGB color2)
{
    twinkle_stars(); // Mengabaikan semua parameter
    
}

// Wrapper untuk comet_tail
void comet_tail_wrapper(CRGB color1, CRGB color2)
{
    comet_tail(); // Mengabaikan semua parameter
    
}

// Wrapper untuk pulse_wave
void pulse_wave_wrapper(CRGB color1, CRGB color2)
{
    pulse_wave(); // Mengabaikan semua parameter
    
}

// Wrapper untuk confetti
void confetti_wrapper(CRGB color1, CRGB color2)
{
    confetti(); // Mengabaikan semua parameter
    
}

// Wrapper untuk rainbow_fade
void rainbow_fade_wrapper(CRGB color1, CRGB color2)
{
    rainbow_fade(); // Mengabaikan color1 dan color2
}

// Wrapper untuk color_bounce
void color_bounce_wrapper(CRGB color1, CRGB color2)
{
    color_bounce(color1, color2); // Menggunakan color1, color2, dan delay_ms
}

// Wrapper untuk color_wave
void color_wave_wrapper(CRGB color1, CRGB color2)
{
    color_wave(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk random_blink
void random_blink_wrapper(CRGB color1, CRGB color2)
{
    random_blink(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_chase
void color_chase_wrapper(CRGB color1, CRGB color2)
{
    color_chase(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_gradient
void color_gradient_wrapper(CRGB color1, CRGB color2)
{
    color_gradient(color1, color2); // Menggunakan color1, color2, dan delay_ms
}

// Wrapper untuk color_pulse
void color_pulse_wrapper(CRGB color1, CRGB color2)
{
    color_pulse(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_ripple
void color_ripple_wrapper(CRGB color1, CRGB color2)
{
    color_ripple(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_burst
void color_burst_wrapper(CRGB color1, CRGB color2)
{
    color_burst(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_sweep
void color_sweep_wrapper(CRGB color1, CRGB color2)
{
    color_sweep(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk fireworks
void fireworks_wrapper(CRGB color1, CRGB color2)
{
    fireworks(); // Mengabaikan color1 dan color2
}

// Wrapper untuk meteor_rain
void meteor_rain_wrapper(CRGB color1, CRGB color2)
{
    meteor_rain(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk lightning
void lightning_wrapper(CRGB color1, CRGB color2)
{
    lightning(); // Mengabaikan color1 dan color2
}

// Wrapper untuk color_shift
void color_shift_wrapper(CRGB color1, CRGB color2)
{
    color_shift(); // Mengabaikan color1 dan color2
}

// Wrapper untuk color_fade_out
void color_fade_out_wrapper(CRGB color1, CRGB color2)
{
    color_fade_out(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk rainbow_comet
void rainbow_comet_wrapper(CRGB color1, CRGB color2)
{
    rainbow_comet(); // Mengabaikan color1 dan color2
}

// Wrapper untuk color_waves
void color_waves_wrapper(CRGB color1, CRGB color2)
{
    color_waves(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk random_pulse
void random_pulse_wrapper(CRGB color1, CRGB color2)
{
    random_pulse(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_gradient_sweep
void color_gradient_sweep_wrapper(CRGB color1, CRGB color2)
{
    color_gradient_sweep(color1, color2); // Menggunakan color1, color2, dan delay_ms
}

// Wrapper untuk color_bounce_wave
void color_bounce_wave_wrapper(CRGB color1, CRGB color2)
{
    color_bounce_wave(color1, color2); // Menggunakan color1, color2, dan delay_ms
}

// Wrapper untuk color_spiral
void color_spiral_wrapper(CRGB color1, CRGB color2)
{
    color_spiral(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_explosion
void color_explosion_wrapper(CRGB color1, CRGB color2)
{
    color_explosion(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_ripple_wave
void color_ripple_wave_wrapper(CRGB color1, CRGB color2)
{
    color_ripple_wave(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_fade_in_out_wave
void color_fade_in_out_wave_wrapper(CRGB color1, CRGB color2)
{
    color_fade_in_out_wave(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_chase_rainbow
void color_chase_rainbow_wrapper(CRGB color1, CRGB color2)
{
    color_chase_rainbow(); // Mengabaikan color1 dan color2
}

// Wrapper untuk breathing_light
void breathing_light_wrapper(CRGB color1, CRGB color2)
{
    breathing_light(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk random_sparkles
void random_sparkles_wrapper(CRGB color1, CRGB color2)
{
    random_sparkles(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_bounce_rainbow
void color_bounce_rainbow_wrapper(CRGB color1, CRGB color2)
{
    color_bounce_rainbow(); // Mengabaikan color1 dan color2
}

// Wrapper untuk color_gradient_fade
void color_gradient_fade_wrapper(CRGB color1, CRGB color2)
{
    color_gradient_fade(color1, color2); // Menggunakan color1, color2, dan delay_ms
}

// Wrapper untuk color_wave_pulse
void color_wave_pulse_wrapper(CRGB color1, CRGB color2)
{
    color_wave_pulse(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_spiral_wave
void color_spiral_wave_wrapper(CRGB color1, CRGB color2)
{
    color_spiral_wave(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_explosion_wave
void color_explosion_wave_wrapper(CRGB color1, CRGB color2)
{
    color_explosion_wave(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_ripple_pulse
void color_ripple_pulse_wrapper(CRGB color1, CRGB color2)
{
    color_ripple_pulse(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_fade_in_out_spiral
void color_fade_in_out_spiral_wrapper(CRGB color1, CRGB color2)
{
    color_fade_in_out_spiral(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk color_chase_spiral
void color_chase_spiral_wrapper(CRGB color1, CRGB color2)
{
    color_chase_spiral(color1); // Menggunakan color1 dan delay_ms
}

// Wrapper untuk aurora_effect
void aurora_effect_wrapper(CRGB color1, CRGB color2)
{
    aurora_effect(); // Mengabaikan color1 dan color2
}

// Wrapper untuk rainbow_wave
void rainbow_wave_wrapper(CRGB color1, CRGB color2)
{
    rainbow_wave(); // Mengabaikan color1 dan color2
}

// Wrapper untuk chasing_dots
void chasing_dots_wrapper(CRGB color1, CRGB color2)
{
    chasing_dots(); // Mengabaikan color1 dan color2
}


Animation animations[] = {
    {"solid_color", solid_color_wrapper},
    {"color_wipe", color_wipe_wrapper},
    {"rainbow_cycle", rainbow_cycle_wrapper},
    {"theater_chase", theater_chase_wrapper},
    {"strobe_light", strobe_light_wrapper},
    {"random_colors", random_colors_wrapper},
    {"fade_in_out", fade_in_out_wrapper},
    {"knight_rider", knight_rider_wrapper},
    {"sparkle", sparkle_wrapper},
    {"gradient_fade", gradient_fade_wrapper},
    {"fire_effect", fire_effect_wrapper},
    {"twinkle_stars", twinkle_stars_wrapper},
    {"comet_tail", comet_tail_wrapper},
    {"pulse_wave", pulse_wave_wrapper},
    {"confetti", confetti_wrapper},
    {"rainbow_fade", rainbow_fade_wrapper},
    {"color_bounce", color_bounce_wrapper},
    {"color_wave", color_wave_wrapper},
    {"random_blink", random_blink_wrapper},
    {"color_chase", color_chase_wrapper},
    {"color_gradient", color_gradient_wrapper},
    {"color_pulse", color_pulse_wrapper},
    {"color_ripple", color_ripple_wrapper},
    {"color_burst", color_burst_wrapper},
    {"color_sweep", color_sweep_wrapper},
    {"fireworks", fireworks_wrapper},
    {"meteor_rain", meteor_rain_wrapper},
    {"lightning", lightning_wrapper},
    {"color_shift", color_shift_wrapper},
    {"color_fade_out", color_fade_out_wrapper},
    {"rainbow_comet", rainbow_comet_wrapper},
    {"color_waves", color_waves_wrapper},
    {"random_pulse", random_pulse_wrapper},
    {"color_gradient_sweep", color_gradient_sweep_wrapper},
    {"color_bounce_wave", color_bounce_wave_wrapper},
    {"color_spiral", color_spiral_wrapper},
    {"color_explosion", color_explosion_wrapper},
    {"color_ripple_wave", color_ripple_wave_wrapper},
    {"color_fade_in_out_wave", color_fade_in_out_wave_wrapper},
    {"color_chase_rainbow", color_chase_rainbow_wrapper},
    {"breathing_light", breathing_light_wrapper},
    {"random_sparkles", random_sparkles_wrapper},
    {"color_bounce_rainbow", color_bounce_rainbow_wrapper},
    {"color_gradient_fade", color_gradient_fade_wrapper},
    {"color_wave_pulse", color_wave_pulse_wrapper},
    {"color_spiral_wave", color_spiral_wave_wrapper},
    {"color_explosion_wave", color_explosion_wave_wrapper},
    {"color_ripple_pulse", color_ripple_pulse_wrapper},
    {"color_fade_in_out_spiral", color_fade_in_out_spiral_wrapper},
    {"color_chase_spiral", color_chase_spiral_wrapper},
    {"aurora_effect", aurora_effect_wrapper},
    {"rainbow_wave", rainbow_wave_wrapper},
    {"chasing_dots", chasing_dots_wrapper},
    {nullptr, nullptr} // Penanda akhir array
  };