/**
 * Lighting the LED with static color
 *
 * Components:
 * 1. RGB LED
 * 2. Resistor 330 Ohm      - 3 units
 * 3. Jumper wires          - 4 units
 *
 * Objectives:
 * 1. Light the LED with specific given color code (hex).
 *
 * For example:
 *  Teal: #008080
 *  Light Purple: #BA9CD9
 */

/** RGB LED pin that connected to PWM */
enum LEDPin { LIGHT_RED = 9, LIGHT_GREEN = 11, LIGHT_BLUE = 10 };

void setup() {}

void loop() {
    lightStaticColor(0x00, 0x80, 0x80);
}

/**
 * If you are familiar with hex color code (i.e. #ffffff),
 *  then you could pass the parameter as single byte value in hex.
 */
void lightStaticColor(unsigned int r, unsigned int g, unsigned int b) {
    analogWrite(LIGHT_RED, r);
    analogWrite(LIGHT_GREEN, g);
    analogWrite(LIGHT_BLUE, b);
}