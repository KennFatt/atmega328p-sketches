/**
 * Print static text into the LCD.
 *
 * Components:
 * 1. LCD (in this case 16x2)
 */
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);     // LiquidCrystal_I2C(address, cols, rows)

void setup() {
    lcd.init();                         // init the lcd
    lcd.backlight();                    // enable backlight (why not tho?)
    lcd.setCursor(0, 0);                // set the cursor to start printing letters
    lcd.print("Within cells");
    lcd.setCursor(4, 1);                // it means row: 1, cols: 5. (everything start with 0)
    lcd.print("interlinked");
}

void loop() {}