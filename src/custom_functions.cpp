#include "Arduino.h"
#include "config_pin.h"

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