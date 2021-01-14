/**
 * Scanning wire addresses.
 * 
 * Components:
 * 1. Any interface module that uses <Wire.h> as the transmission
 *      i.e. i2c interface module or any other TWI
 * 
 * Objectives:
 * 1. Get the slave address from the connected devices
 * 2. Print the address with Serial monitor
 */
#include <Wire.h>

/** Scan will run periodically with specific given delay time */
static const int SCAN_DELAY_TIME = 5000;                            // run the scanner each 5 seconds

void setup() {
    Wire.begin();                                                   // begin the wire
    Serial.begin(9600);

    while (!Serial)                                                 // wait for serial communication
        ;
    Serial.println("[*] Starting I2C Scanner...");
}

void loop() {
    Serial.println("[*] Start scanning...");

    startScan();

    delay(SCAN_DELAY_TIME);
}

/**
 * Scan within 1 to 126 address (slave address always 1 byte sizes).
 */
void startScan() {
    byte error, address;
    int scannedDevices = 0;

    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission(address);

        if (error == 0) {                                           // 0 means no error and found a device
            Serial.print("[+] Found device with address: ");        // in my case, i got 27 (it is a hex value, you should write 0x27)
            Serial.print(address, HEX);
            Serial.println();

            scannedDevices++;
        } else if (error == 4) {                                    // other than 0, it means an error occured
            Serial.print("[!] Uknown error at address: ");
            Serial.print(address, HEX);
            Serial.println();
        }
    }

    if (scannedDevices == 0) {
        Serial.println("[!] No devices are scanned!");
    }
}