#include "Web.h"
#include "./LedAnimations.h"

Config cfg;
Preferences prefs;
WebServer server(80);

void loadConfig()
{
    Serial.println("Load config from NVS");

    prefs.begin("cfg", true);

    cfg.ssid = prefs.getString("ssid", "");
    cfg.pass = prefs.getString("pass", "");

    cfg.useStaticIP = prefs.getBool("static", false);
    cfg.ip.fromString(prefs.getString("ip", "192.168.1.50"));
    cfg.gateway.fromString(prefs.getString("gw", "192.168.1.1"));
    cfg.subnet.fromString(prefs.getString("sn", "255.255.255.0"));

    cfg.ledPin = prefs.getUChar("ledPin", 13);
    cfg.buttonPin = prefs.getUChar("btnPin", 2);
    cfg.brightness = prefs.getUChar("bright", 128);
    cfg.numLeds = prefs.getUShort("ledCnt", 36);

    prefs.end();

    Serial.println("Config loaded:");
    Serial.println("SSID: " + cfg.ssid);
    Serial.println("Static IP: " + String(cfg.useStaticIP));
    Serial.println("IP: " + cfg.ip.toString());
    Serial.println("Gateway: " + cfg.gateway.toString());
    Serial.println("Subnet: " + cfg.subnet.toString());
    Serial.println("LED Pin: " + String(cfg.ledPin));
    Serial.println("Button Pin: " + String(cfg.buttonPin));
    Serial.println("Brightness: " + String(cfg.brightness));
    Serial.println("LED Count: " + String(cfg.numLeds));
}

bool connectWiFi()
{
    if (cfg.ssid.length() == 0)
    {
        Serial.println("SSID kosong");
        return false;
    }

    Serial.println("Connecting to WiFi");
    Serial.println("SSID: " + cfg.ssid);

    WiFi.mode(WIFI_STA);

    if (cfg.useStaticIP)
    {
        Serial.println("Using static IP");
        WiFi.config(cfg.ip, cfg.gateway, cfg.subnet);
    }

    WiFi.begin(cfg.ssid.c_str(), cfg.pass.c_str());

    for (int i = 1; i <= 5; i++)
    {
        Serial.print("Attempt ");
        Serial.println(i);

        if (WiFi.status() == WL_CONNECTED)
        {
            Serial.println("WiFi connected");
            Serial.println("IP: " + WiFi.localIP().toString());
            return true;
        }
        delay(2000);
    }

    Serial.println("WiFi failed");
    return false;
}

void startAP()
{
    Serial.println("Starting AP mode");

    WiFi.mode(WIFI_AP);
    WiFi.softAP("ESP32-Config");

    Serial.println("AP started");
    Serial.println("AP IP: " + WiFi.softAPIP().toString());
}

void saveConfig()
{
    Serial.println("Saving config to NVS");

    prefs.begin("cfg", false);

    prefs.putString("ssid", cfg.ssid);
    prefs.putString("pass", cfg.pass);

    prefs.putBool("static", cfg.useStaticIP);
    prefs.putString("ip", cfg.ip.toString());
    prefs.putString("gw", cfg.gateway.toString());
    prefs.putString("sn", cfg.subnet.toString());

    prefs.putUChar("ledPin", cfg.ledPin);
    prefs.putUChar("btnPin", cfg.buttonPin);
    prefs.putUChar("bright", cfg.brightness);
    prefs.putUShort("ledCnt", cfg.numLeds);

    prefs.end();

    Serial.println("Config saved");
}

void updateIfExists(const String &key, String &target)
{
    if (server.hasArg(key))
    {
        target = server.arg(key);
        Serial.println(key + " updated");
    }
}

void updateIfExists(const String &key, uint8_t &target)
{
    if (server.hasArg(key))
    {
        target = server.arg(key).toInt();
        Serial.println(key + " updated");
    }
}

void updateIfExists(const String &key, uint16_t &target)
{
    if (server.hasArg(key))
    {
        target = server.arg(key).toInt();
        Serial.println(key + " updated");
    }
}

void setupWeb()
{
    Serial.println("Starting web server");

    server.on("/", HTTP_GET, []()
              {
    Serial.println("HTTP GET /");

    String html =
  "<form method='POST' action='/'>"

  "SSID:<input name='ssid' value='" + cfg.ssid + "'><br>"
  "PASS:<input name='pass' value='" + cfg.pass + "'><br><br>"

  "Static IP:<input type='checkbox' name='static' " +
  String(cfg.useStaticIP ? "checked" : "") + "><br>"

  "IP:<input name='ip' value='" + cfg.ip.toString() + "'><br>"
  "Gateway:<input name='gw' value='" + cfg.gateway.toString() + "'><br>"
  "Subnet:<input name='sn' value='" + cfg.subnet.toString() + "'><br><br>"

  "LED_PIN:<input name='led' value='" + String(cfg.ledPin) + "'><br>"
  "BUTTON_PIN:<input name='btn' value='" + String(cfg.buttonPin) + "'><br>"
  "LED_COUNT:<input name='cnt' value='" + String(cfg.numLeds) + "'><br><br>"

  "<button>Save Config</button>"
  "</form><hr>"

  "<form method='POST' action='/brightness'>"
  "BRIGHTNESS (0-255):<input name='br' value='" + String(cfg.brightness) + "'>"
  "<button>Set Brightness</button>"
  "</form><br>"

  "Current IP: " + WiFi.localIP().toString();


    server.send(200, "text/html", html); });

    server.on("/", HTTP_POST, []()
              {
        Serial.println("HTTP POST /");

        cfg.ssid = server.arg("ssid");
        cfg.pass = server.arg("pass");

        cfg.useStaticIP = server.hasArg("static");
        cfg.ip.fromString(server.arg("ip"));
        cfg.gateway.fromString(server.arg("gw"));
        cfg.subnet.fromString(server.arg("sn"));

        cfg.ledPin = server.arg("led").toInt();
        cfg.buttonPin = server.arg("btn").toInt();
        cfg.brightness = server.arg("br").toInt();
        cfg.numLeds = server.arg("cnt").toInt();

        Serial.println("New config received");
        saveConfig();

        server.send(200, "text/html", "Saved. Reboot ESP32.");
        ESP.restart(); });

    server.on("/brightness", HTTP_POST, []()
              {
    Serial.println("HTTP POST /brightness");

    if (!server.hasArg("br")) {
        server.send(400, "text/plain", "Parameter br tidak ada");
        return;
    }

    int br = server.arg("br").toInt();

    if (br < 0) br = 0;
    if (br > 255) br = 255;

    cfg.brightness = br;
    saveConfig();

    FastLED.setBrightness(cfg.brightness);
    FastLED.show();

    server.send(200, "text/plain", "Brightness updated"); });

    server.begin();
    Serial.println("Web server running");
}
