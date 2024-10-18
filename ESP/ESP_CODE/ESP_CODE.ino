#include <WiFi.h>;
#include <WiFiMulti.h>;
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

WiFiMulti wifiMulti;

const int ON = 0;
const int OFF = 1;

const uint32_t connectTimeoutMs = 5000;

const int RELAY_1 = 32;
const int RELAY_2 = 33;
const int RELAY_3 = 25;
const int RELAY_4 = 26;
const int RELAY_5 = 27;
const int RELAY_6 = 14;
const int RELAY_7 = 12;
const int RELAY_8 = 13;
const int wifiStatus = 2;

int RELAY_STAT[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
int pinCount = 8;

void setup() {
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);
  pinMode(RELAY_6, OUTPUT);
  pinMode(RELAY_7, OUTPUT);
  pinMode(RELAY_8, OUTPUT);
  pinMode(wifiStatus, OUTPUT);

  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  digitalWrite(RELAY_3, HIGH);
  digitalWrite(RELAY_4, HIGH);
  digitalWrite(RELAY_5, HIGH);
  digitalWrite(RELAY_6, HIGH);
  digitalWrite(RELAY_7, HIGH);
  digitalWrite(RELAY_8, HIGH);

  Serial.begin(115200);

  wifiMulti.addAP("WIFI1 ", "PASSWORD1");
  wifiMulti.addAP("WIFI2 ", "PASSWORD2");
  wifiMulti.addAP("WIFI3 ", "PASSWORD3");
  wifiMulti.addAP("WIFI4 ", "PASSWORD4");


  // WiFi.begin(ssid, password);
  // Serial.print("connecting to WiFi");
  // while (WiFi.status() != WL_CONNECTED) {
  //   Serial.print(".");
  //   delay(500);
  // }

  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }

  Serial.println("Connecting Wifi...");
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    digitalWrite(wifiStatus, HIGH);
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  if (wifiMulti.run(connectTimeoutMs) == WL_CONNECTED) {
    Serial.print("WiFi connected: ");
    Serial.print(WiFi.SSID());
    Serial.print(" ");
    Serial.println(WiFi.RSSI());
  } else {
    Serial.println("WiFi not connected!");
  }

  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient client;
    // here replace "ORIGIN.COM" with your website origin. 
    client.begin("https://ORIGIN.COM/relay/relayStatus");
    int httpCode = client.GET();

    // if (httpCode >= 0) {
    String payload = client.getString();


    Serial.println(payload);
    Serial.println("http code :" + String(httpCode));

    char Json[500];

    payload.replace(" ", "");
    payload.replace("\n", "");
    payload.trim();
    payload.toCharArray(Json, 500);
    StaticJsonDocument<200> doc;
    deserializeJson(doc, Json);

    for (int i = 0; i < pinCount; i++) {
      int output = doc["relayStatus"][i];
      RELAY_STAT[i] = int(output);
      Serial.println(output);
    }

    digitalWrite(RELAY_1, RELAY_STAT[0]);
    digitalWrite(RELAY_2, RELAY_STAT[1]);
    digitalWrite(RELAY_3, RELAY_STAT[2]);
    // digitalWrite(RELAY_3, LOW);
    digitalWrite(RELAY_4, RELAY_STAT[3]);
    digitalWrite(RELAY_5, RELAY_STAT[4]);
    digitalWrite(RELAY_6, RELAY_STAT[5]);
    digitalWrite(RELAY_7, RELAY_STAT[6]);
    digitalWrite(RELAY_8, RELAY_STAT[7]);

    delay(500);

  } else {
    Serial.println("Connection Lost!!!");
    delay(15000);
  }
}
