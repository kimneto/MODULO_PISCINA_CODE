#ifndef CUSTOM_FUNCTIONS_H
#define CUSTOM_FUNCTIONS_H
void setup_wifi();
void setupOutput();
void setupInput();
void reconnect(PubSubClient client);
void blinkLED(int led_pin, int duration );
void checarSensorDeAlagamento();

#endif