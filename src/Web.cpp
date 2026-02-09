#include "Web.h"
#include "./LedAnimations.h"
#include "./SavedWifi.h"
#include "index_html.h"

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
    // Serial.println("SSID: " + cfg.ssid);
    // Serial.println("Static IP: " + String(cfg.useStaticIP));
    // Serial.println("IP: " + cfg.ip.toString());
    // Serial.println("Gateway: " + cfg.gateway.toString());
    // Serial.println("Subnet: " + cfg.subnet.toString());
    Serial.println("LED Pin: " + String(cfg.ledPin));
    Serial.println("Button Pin: " + String(cfg.buttonPin));
    Serial.println("Brightness: " + String(cfg.brightness));
    Serial.println("LED Count: " + String(cfg.numLeds));
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

    server.on("/welcome", HTTP_GET, []()
              {
    Serial.println("HTTP GET /");
    String html = String(INDEX_HTML);

  "Current IP: " + WiFi.localIP().toString();
    server.send(200, "text/html", html); });

    server.on("/", HTTP_GET, []()
              {
        Serial.println("HTTP GET /config");

        String html = "<!doctype html> <html> <head>" 
    "<meta charset='utf-8'>" 
    "<title></title>" 
  "</head>"
  "<body>"
    "<script src='http://192.168.2.50/scriptt.js'></script>"
  "</body>"
"</html>";
        server.send(200, "text/html", html); });

    server.on("/config/data", HTTP_GET, []()
              {
  Serial.println("HTTP GET /config/data");

  String json = "{";

  json += "\"wifiList\":[";

  for (int i = 0; i < wifiCount; i++) {
    json += "{";
    json += "\"ssid\":\"" + wifiList[i].ssid + "\",";
    json += "\"useStatic\":" + String(wifiList[i].useStatic ? "true" : "false") + ",";
    json += "\"ip\":\"" + wifiList[i].ip.toString() + "\",";
    json += "\"gateway\":\"" + wifiList[i].gw.toString() + "\",";
    json += "\"subnet\":\"" + wifiList[i].sn.toString() + "\"";
    json += "}";

    if (i < wifiCount - 1) json += ",";
  }

  json += "],";

  json += "\"ledPin\":" + String(cfg.ledPin) + ",";
  json += "\"buttonPin\":" + String(cfg.buttonPin) + ",";
  json += "\"brightness\":" + String(cfg.brightness) + ",";
  json += "\"numLeds\":" + String(cfg.numLeds);

  json += "}";

  server.send(200, "application/json", json); });

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

    server.on("/wifi/add", HTTP_POST, []()
              {
  Serial.println("HTTP POST /wifi/add");

  if (!server.hasArg("ssid")) {
    server.send(400, "text/plain", "SSID tidak ada");
    return;
  }

  String ssid = server.arg("ssid");
  String pass = server.arg("pass");

  bool useStatic = server.hasArg("static");

  IPAddress ip, gw, sn;
  if (useStatic) {
    ip.fromString(server.arg("ip"));
    gw.fromString(server.arg("gw"));
    sn.fromString(server.arg("sn"));
  }

  addOrUpdateWiFi(
    ssid,
    pass,
    useStatic,
    ip,
    gw,
    sn
  );

  Serial.println("WiFi saved: " + ssid);

  server.send(200, "application/json",
    "{\"status\":\"ok\"}"
  ); });

    server.on("/wifi/test", HTTP_POST, []()
              {
  String ssid = server.arg("ssid");
  String pass = server.arg("pass");

  WiFi.mode(WIFI_AP_STA);

  WiFi.begin(ssid.c_str(), pass.c_str());

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(300);
  }

  if (WiFi.status() != WL_CONNECTED) {
    server.send(500, "application/json", "{\"ok\":false}");
    return;
  }

  IPAddress ip = WiFi.localIP();
  IPAddress gw = WiFi.gatewayIP();
  IPAddress sn = WiFi.subnetMask();

  String json =
    "{"
    "\"ok\":true,"
    "\"ip\":\"" + ip.toString() + "\","
    "\"gw\":\"" + gw.toString() + "\","
    "\"sn\":\"" + sn.toString() + "\""
    "}";

  WiFi.disconnect(false); // STA putus, AP tetap hidup
  server.send(200, "application/json", json); });

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
