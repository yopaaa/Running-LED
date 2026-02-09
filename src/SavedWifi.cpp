#include "./SavedWifi.h"
#include "./Web.h"

WiFiCred wifiList[MAX_WIFI];
uint8_t wifiCount = 0;

void saveWiFiList() {
  prefs.begin("wifi", false);
  prefs.putUChar("count", wifiCount);

  for (int i = 0; i < wifiCount; i++) {
    String k = String(i);

    prefs.putString(("s" + k).c_str(), wifiList[i].ssid);
    prefs.putString(("p" + k).c_str(), wifiList[i].pass);
    prefs.putBool(("st" + k).c_str(), wifiList[i].useStatic);

    prefs.putString(("ip" + k).c_str(), wifiList[i].ip.toString());
    prefs.putString(("gw" + k).c_str(), wifiList[i].gw.toString());
    prefs.putString(("sn" + k).c_str(), wifiList[i].sn.toString());
  }

  prefs.end();
}


void loadWiFiList() {
  prefs.begin("wifi", true);

  wifiCount = prefs.getUChar("count", 0);
  if (wifiCount > MAX_WIFI) wifiCount = MAX_WIFI;

  for (int i = 0; i < wifiCount; i++) {
    String k = String(i);

    wifiList[i].ssid = prefs.getString(("s" + k).c_str(), "");
    wifiList[i].pass = prefs.getString(("p" + k).c_str(), "");
    wifiList[i].useStatic = prefs.getBool(("st" + k).c_str(), false);

    wifiList[i].ip.fromString(prefs.getString(("ip" + k).c_str(), ""));
    wifiList[i].gw.fromString(prefs.getString(("gw" + k).c_str(), ""));
    wifiList[i].sn.fromString(prefs.getString(("sn" + k).c_str(), ""));
  }

  prefs.end();
}


int scanWiFi(String found[], int max) {
  Serial.println("Scan WiFi...");

  int n = WiFi.scanNetworks();
  int count = 0;

  if (n <= 0) {
    Serial.println("Tidak ada WiFi ditemukan");
    return 0;
  }

  Serial.print("Ditemukan ");
  Serial.print(n);
  Serial.println(" jaringan");

  for (int i = 0; i < n && count < max; i++) {
    String ssid = WiFi.SSID(i);

    found[count++] = ssid;

    Serial.print(count);
    Serial.print(". ");
    Serial.print(ssid);
    Serial.print(" | RSSI: ");
    Serial.print(WiFi.RSSI(i));
    Serial.print(" dBm");
    Serial.print(" | Enkripsi: ");
    Serial.println(
      WiFi.encryptionType(i) == WIFI_AUTH_OPEN
        ? "OPEN"
        : "SECURE"
    );
  }

  Serial.println("Scan selesai");
  return count;
}


bool connectSavedWiFi() {
  String found[10];
  int foundCount = scanWiFi(found, 10);

  for (int i = 0; i < wifiCount; i++) {
    for (int j = 0; j < foundCount; j++) {
      if (wifiList[i].ssid == found[j]) {

        WiFi.mode(WIFI_STA);

        if (wifiList[i].useStatic) {
          WiFi.config(
            wifiList[i].ip,
            wifiList[i].gw,
            wifiList[i].sn
          );
        }

        WiFi.begin(
          wifiList[i].ssid.c_str(),
          wifiList[i].pass.c_str()
        );

        unsigned long start = millis();
        while (millis() - start < 8000) {
          if (WiFi.status() == WL_CONNECTED) {
            Serial.println("--------------------------");
            Serial.println("Connected to: " + wifiList[i].ssid);
            Serial.print("Current IP  : ");
            Serial.println(WiFi.localIP()); // Menampilkan IP Address
            Serial.print("Gateway     : ");
            Serial.println(WiFi.gatewayIP());
            Serial.println("--------------------------");
            return true;
          }
          delay(500);
        }
      }
    }
  }

  return false;
}


void addOrUpdateWiFi(
  String ssid,
  String pass,
  bool useStatic,
  IPAddress ip,
  IPAddress gw,
  IPAddress sn
) {
  for (int i = 0; i < wifiCount; i++) {
    if (wifiList[i].ssid == ssid) {
      wifiList[i].pass = pass;
      wifiList[i].useStatic = useStatic;
      wifiList[i].ip = ip;
      wifiList[i].gw = gw;
      wifiList[i].sn = sn;
      saveWiFiList();
      return;
    }
  }

  if (wifiCount < MAX_WIFI) {
    wifiList[wifiCount].ssid = ssid;
    wifiList[wifiCount].pass = pass;
    wifiList[wifiCount].useStatic = useStatic;
    wifiList[wifiCount].ip = ip;
    wifiList[wifiCount].gw = gw;
    wifiList[wifiCount].sn = sn;
    wifiCount++;
  } else {
    wifiList[0].ssid = ssid;
    wifiList[0].pass = pass;
    wifiList[0].useStatic = useStatic;
    wifiList[0].ip = ip;
    wifiList[0].gw = gw;
    wifiList[0].sn = sn;
  }

  saveWiFiList();
}



void startAP()
{
    Serial.println("Starting AP mode");

    WiFi.mode(WIFI_AP);
    WiFi.softAP("ESP32-Config");

    Serial.println("AP started");
    Serial.println("AP IP: " + WiFi.softAPIP().toString());

    // Inisialisasi mDNS
  if (MDNS.begin("esp")) { // Akan bisa diakses via http://esp.local
    Serial.println("mDNS responder started: http://esp.local");
  }
  
  // Tambahkan service HTTP agar mDNS lebih mudah ditemukan oleh browser
  MDNS.addService("http", "tcp", 80);
}