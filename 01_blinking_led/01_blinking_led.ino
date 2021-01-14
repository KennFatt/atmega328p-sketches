/**
 * Blinking LED
 * 
 * Components:
 * 1. LED (Red) 2V 20mA
 * 2. Resistor 270 Ohm
 * 
 * Objectives:
 * 1. LED Blinking in every 500ms
 * 
 * STATUS: Succeed
 */

/** Power source for the LED */
static const int pinLed = 2;

void setup() {
    pinMode(pinLed, OUTPUT);
}

void loop() {
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinLed, LOW);
    delay(500);
}