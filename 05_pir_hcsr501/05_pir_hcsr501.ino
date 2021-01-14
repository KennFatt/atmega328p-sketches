/**
 * Pyroelectric Infra Red Motion Sensor.
 * 
 * Components:
 * 1. HC-SR501
 * 
 * Objectives:
 * 1. Detecting a motion (living object) within sensor's range value
 * 
 * NOTE: This code effectively tested with L mode (non-repeatable)
 *          and by adjusting the "sensitivity control" pot a little bit accurate (clockwise).
 */

/** Data pin */
static const int PIN_PIR = 8;

/** Latest sensor's state */
static int pirLastState = LOW;

/** Recent most sensor's state */
static int pirCurrentState = LOW;               // it will changes every single loop

void setup() {
    pinMode(PIN_PIR, INPUT);

    Serial.begin(9600);
}

void loop() {
    pirCurrentState = digitalRead(PIN_PIR);     // update recent state from the sensor
    unsigned long now = millis();               // for debugging purposes

    if (pirCurrentState != pirLastState) {      // change the `pirLastState` if the recent most state has different value
        pirLastState = pirCurrentState;

        if (pirLastState == HIGH) {
            Serial.print(now);
            Serial.println("> Motion detected");
        }
    }
}
