/**
 * RGB Color Cycle
 *
 * Components:
 * 1. RGB LED (4 pin)
 *      Red: 2.0 volt
 *      Ground              - The longest one
 *      Blue: 3.4 volt
 *      Green: 3.4 volt     - The shortest one
 *
 * 2. 330 Ohm               - 3 units for each RGB LED pin (except the ground)
 * 3. Jumper wires          - 3 for PWM and 1 for GND
 *
 * Objectives:
 * 1. Cycling color from RG, GB, BR; RGB color
 */

/** RGB Pin, these pins are connected to PWM */
enum LEDPin /* : uint8_t */ {
    LIGHT_RED = 9,
    LIGHT_BLUE = 10,
    LIGHT_GREEN = 11
};

/** Struct to hold the light intensity of each R,G,B color */
struct LightIntensityState {
    int r = 0;
    int g = 0;
    int b = 0;
};

LightIntensityState lightState;

/**
 * Color changing speed for 1 cycle.
 *
 * For example:
 *  0: #FF0000
 *  1: #FE0100
 *  2: #FD0200
 *
 * to change from first iteration (0) to the next one (1)
 *  need a given time in millisecond.
 */
static const int displayTime = 25;

void setup() {
    /** No need to pinMode() since we're using PWM */
}

void loop() {
    /**
     * What actually we did here:
     * Cycles:
     *  Red,Green:
     *      Iterations:
     *          0: #FF0000
     *          1: #FE0100
     *          2: #FD0200
     *          ...
     *          255: #00FF00
     *  Green,Blue:
     *      Iterations:
     *          0: #00FF00
     *          1: #00FE01
     *          2: #00FD02
     *          ...
     *          255: #0000FF
     *  Blue,Red:
     *      Iterations:
     *          0: #0000FF
     *          1: #0100FE
     *          2: #0200FD
     *          ...
     *          255: #FF0000
     *
     * by doing so, we have a smooth RGB transition.
     */
    for (lightState.g = 0; lightState.g <= 255; lightState.g++) {
        lightState.r = 255 - lightState.g;
        analogWrite(LIGHT_GREEN, lightState.g);
        analogWrite(LIGHT_RED, lightState.r);
        delay(displayTime);
    }

    for (lightState.b = 0; lightState.b <= 255; lightState.b++) {
        lightState.g = 255 - lightState.b;
        analogWrite(LIGHT_BLUE, lightState.b);
        analogWrite(LIGHT_GREEN, lightState.g);
        delay(displayTime);
    }

    for (lightState.r = 0; lightState.r <= 255; lightState.r++) {
        lightState.b = 255 - lightState.r;
        analogWrite(LIGHT_RED, lightState.r);
        analogWrite(LIGHT_BLUE, lightState.b);
        delay(displayTime);
    }
}