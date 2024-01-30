#include <Arduino.h>
#include <config_pin.h>
#include <custom_functions.h>

void setup() {
Serial.begin(9600);
setupOutput();
setupInput();
}

void loop() {
blinkLED(KIM_PIN_LED_ALAGAMENTO, 1500);
}

