#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
ESP8266WebServer server(80);

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("SEMEC Carrinho 01");
  dnsServer.setTTL(300);
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(53, "*", apIP);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  server.on("/", HTTP_GET, []() {
    sendHeaders();
    send_page_index();
  });
  server.on("/0_0", HTTP_POST, [](){ digitalWrite(0, 0); });
  server.on("/0_1", HTTP_POST, [](){ digitalWrite(0, 1); });
  server.on("/1_0", HTTP_POST, [](){ digitalWrite(1, 0); });
  server.on("/1_1", HTTP_POST, [](){ digitalWrite(1, 1); });
  server.on("/2_0", HTTP_POST, [](){ digitalWrite(2, 0); });
  server.on("/2_1", HTTP_POST, [](){ digitalWrite(2, 1); });
  server.on("/3_0", HTTP_POST, [](){ digitalWrite(3, 0); });
  server.on("/3_1", HTTP_POST, [](){ digitalWrite(3, 1); });
  server.onNotFound([]() {
    sendHeaders();
    server.send(200, "text/plain", "Not found");
  });
  server.begin();

  while(true) {
    dnsServer.processNextRequest();
    server.handleClient();
  }
}

void loop() {}
