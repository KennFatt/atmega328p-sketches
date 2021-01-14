/**
 * Measure soil moisture.
 * 
 * Components:
 * 1. Soil moisture sensors module (the one that has LM393 Comparator IC)
 * 
 * Objectives:
 * 1. Measure the moisture value from analog input
 */

/** Connected to the A0 pin (both MCU and LM393) */
static const int ANALOG_PIN = A0;

/** Raw value from analogRead() */
static int soilValue = 0;

/** Mapped value (to precentage) from raw value above */
static int mappedSoilValue = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    soilValue = analogRead(ANALOG_PIN);                         // When not sensing the soil (probe are not connected to the object) my sensor give me
    mappedSoilValue = map(soilValue, 455, 10, 0, 100);          // raw value about 455. You should adjust it depends with yours.

    Serial.print("Moisture: ");                                 // Moisture: 0%, Raw value: 455
    Serial.print(mappedSoilValue);
    Serial.print("%");
    Serial.print(", Raw value: ");
    Serial.println(soilValue);

    delay(500);
}