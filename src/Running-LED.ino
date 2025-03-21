#include "./LedAnimations.h"

#define LED_PIN 23 // Pin data LED strip
#define BUTTON_PIN 2   // Pin tombol untuk beralih animasi
#define BRIGHTNESS 128 // Brightness level (0–255)

const int NUM_LEDS = 60; // Jumlah LED
CRGB leds[NUM_LEDS];     // Array LED
uint8_t heat[60];

// Variabel global
int current_animation_index = 0; // Indeks animasi saat ini

// Prototipe fungsi
void handle_button_press();

void setup()
{
  Serial.begin(9600);
  Serial.println("Running LED");
  const char *animation_name = animations[current_animation_index].name;

  // Cetak nama animasi ke serial monitor
  Serial.print("Menjalankan animasi: ");
  Serial.println(animation_name);

  // Inisialisasi FastLED
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  // Inisialisasi tombol
  pinMode(BUTTON_PIN, INPUT_PULLDOWN); // Menggunakan pull-up internal
}

void loop()
{
  // Tangani penekanan tombol
  handle_button_press();
  // Serial.println("...");
  // Jalankan animasi yang sedang aktif
  const char *current_animation_name = animations[current_animation_index].name;
  AnimationFunction current_animation = find_animation(current_animation_name);
  if (current_animation)
  {
    current_animation(CRGB::Red, CRGB::Blue); // Jalankan animasi dengan delay 20ms
  }
}


  static unsigned long last_button_press = 0; // Waktu terakhir tombol ditekan
  const unsigned long debounce_delay = 200;   // Delay debounce untuk mencegah bouncing

// Fungsi untuk menangani penekanan tombol
void handle_button_press()
{
  if (digitalRead(BUTTON_PIN) == HIGH)
  { // Tombol ditekan (LOW karena pull-up)
    if (millis() - last_button_press > debounce_delay)
    {
      // Pindah ke animasi berikutnya
      current_animation_index++;
      if (current_animation_index >= 53)
      { // Reset ke awal jika melebihi jumlah animasi
        current_animation_index = 0;
      }

      // Dapatkan nama animasi dari array
      const char *animation_name = animations[current_animation_index].name;

      // Cetak nama animasi ke serial monitor
      Serial.print("Menjalankan animasi: ");
      Serial.println(animation_name);

      // Update waktu terakhir tombol ditekan
      last_button_press = millis();
    }
  }
}
