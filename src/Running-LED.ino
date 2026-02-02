#include "./LedAnimations.h"
#include "Web.h"

#define LED_PIN 13

uint8_t heat[60];

CRGB *leds = nullptr;
uint16_t ledCount = 0;

// Variabel global
int current_animation_index = 0;       // Indeks animasi saat ini
bool led_enabled = true;               // LED aktif secara default
bool normal_light_mode = false;        // Menyimpan status mode lampu biasa
uint8_t light_warmth = 128;            // Nilai kehangatan (0–255)
CRGB warm_color = CRGB(255, 160, 50);  // Orange warm
CRGB cold_color = CRGB(180, 240, 255); // Biru dingin

CRGB interpolate_color(const CRGB &cold, const CRGB &warm, uint8_t value)
{
  float ratio = value / 255.0;
  uint8_t r = cold.r + ratio * (warm.r - cold.r);
  uint8_t g = cold.g + ratio * (warm.g - cold.g);
  uint8_t b = cold.b + ratio * (warm.b - cold.b);
  return CRGB(r, g, b);
}

// Prototipe fungsi
void handle_button_press();

void setup()
{
  Serial.begin(9600);
  loadConfig();

  if (!connectWiFi())
  {
    startAP();
  }
  setupWeb();

  Serial.println("Running LED");
  Serial.print("Code compiled on ");
  Serial.println(__DATE__); // Tanggal kompilasi, misalnya "May  1 2025"
  const char *animation_name = animations[current_animation_index].name;

  ledCount = cfg.numLeds;
  leds = new CRGB[ledCount];

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, ledCount);
  FastLED.setBrightness(cfg.brightness);
  FastLED.clear();
  FastLED.show();

  // Inisialisasi tombol
  pinMode(cfg.buttonPin, INPUT_PULLDOWN);
}

void loop()
{
  server.handleClient();
  // handle_button_press();

  const char *current_animation_name = animations[current_animation_index].name;
  AnimationFunction current_animation = find_animation(current_animation_name);

  if (led_enabled && !normal_light_mode && current_animation)
  {
    current_animation(CRGB::Red, CRGB::Blue);
  }
}

static unsigned long last_button_press = 0;
const unsigned long debounce_delay = 200;

// Fungsi untuk menangani penekanan tombol
void handle_button_press()
{
  if (digitalRead(cfg.buttonPin) == HIGH)
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
