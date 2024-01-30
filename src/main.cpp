#include <Arduino.h>
#include <PubSubClient.h>
#include <config_pin.h>
#include <secreto.h>
#include <custom_functions.h>
#include <WiFi.h>


WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
Serial.begin(9600);
setupOutput();
setupInput();
}

void loop() {
    if (!client.connected()) {
     
    reconnect(client.);

  }
  client.loop();
checarSensorDeAlagamento();


}

