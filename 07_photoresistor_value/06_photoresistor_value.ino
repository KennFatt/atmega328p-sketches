/**
 * Read the resistance value from Photoresistor.
 *
 * Components:
 * 1. Photoresistor (LDR GL5516)
 * 2. Resistor (in this case, i'm using 10K)
 *
 * Objectives:
 * 1. Read the resistance value from the photoresistor as
 *      an analog input.
 */

/** Pin that connected to one of Photoresistor's polar */
static const int ANALOG_PIN = A0;

static int resistanceValue = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    resistanceValue = analogRead(ANALOG_PIN);

    Serial.print("Resistance value: ");
    Serial.println(resistanceValue);

    delay(100);
}