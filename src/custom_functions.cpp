#include "Arduino.h"
#include "config_pin.h"
#include <secreto.h>
#include <WiFi.h>
#include <PubSubClient.h>

void setupOutput() {
  pinMode(KIM_PIN_LED_ALAGAMENTO, OUTPUT);
}

void setupInput() {
  pinMode(KIM_PIN_SENSOR_ALAGAMENTO, INPUT);
}


void blinkLED(int led_pin, int duration) {
  digitalWrite(led_pin, HIGH);
  delay(duration);
  digitalWrite(led_pin, LOW);
  delay(duration);
}

void checarSensorDeAlagamento() {
  int sensorValue = digitalRead(KIM_PIN_SENSOR_ALAGAMENTO);
  if (sensorValue == HIGH) {
    client.publish("casa/sensor/alagamento", "Alagado");
  } else {
    client.publish("casa/sensor/alagamento", "Seco");
  }
  if (sensorValue == HIGH) {
    blinkLED(KIM_PIN_LED_ALAGAMENTO, 100);
  }
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect(PubSubClient client) {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT Broker...");
    if (client.connect("arduinoClient")) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}