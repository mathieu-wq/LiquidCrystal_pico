#include <stdio.h>
#include "pico/stdlib.h"

#include "LiquidCrystal_pico.hpp"

#define LCD_RS_PIN 14
#define LCD_ENABLE_PIN 15
#define LCD_D4_PIN 10
#define LCD_D5_PIN 11
#define LCD_D6_PIN 12
#define LCD_D7_PIN 13

uint8_t char_down_arrow[8] = { // Here is how you create a custom character (e.g. a down arrow)
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b01110,
  0b00100
};

LiquidCrystal lcd(LCD_RS_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

int main()
{
    lcd.begin(20, 4);
    lcd.print("Hello, world!");
    lcd.createChar(0, char_down_arrow); // Create a custom character at address 0 in CG RAM
    lcd.setCursor(0, 1); // Go to the second line
    lcd.print((char) 0); // Print the custom character at address 0 in CG RAM
    while (true) {
        sleep_ms(1000);
    }
    return 0;
}