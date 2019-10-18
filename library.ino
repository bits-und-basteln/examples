#include "Bub.h"

Canvas canvas;
Ghost ghost;
Hat hat;

void setup() {}

long HAT_COLOR = 0xcc0000;
long GHOST_COLOR = 0xf542aa;
long EYE_COLOR = 0x1eff00;

void loop() {
    canvas.clear();
    canvas.draw(&ghost, GHOST_COLOR, 5, 6);
    canvas.draw(&hat, HAT_COLOR, 4, 1);
    canvas.show();
    delay(500);
    canvas.clear();
    canvas.draw(&ghost, GHOST_COLOR, 5, 6);
    canvas.draw(&hat, HAT_COLOR, 4, 2);
    canvas.show();
    delay(500);
    canvas.clear();
    canvas.draw(&ghost, GHOST_COLOR, 5, 6);
    canvas.draw(&hat, HAT_COLOR, 4, 3);
    canvas.show();
    delay(500);
    canvas.clear();
    canvas.draw(&ghost, GHOST_COLOR, 5, 6);
    canvas.draw(&hat, HAT_COLOR, 4, 4);
    canvas.show();
    delay(500);
    canvas.pixel(6, 8, EYE_COLOR);
    canvas.pixel(8, 8, EYE_COLOR);
    canvas.show();
    delay(500);
    canvas.pixel(6, 8, 0x000000);
    canvas.pixel(8, 8, 0x000000);
    canvas.show();
    delay(500);
    canvas.pixel(6, 8, EYE_COLOR);
    canvas.pixel(8, 8, EYE_COLOR);
    canvas.show();
    delay(500);
    canvas.pixel(6, 8, 0x000000);
    canvas.pixel(8, 8, 0x000000);
    canvas.show();
    delay(500);
    canvas.pixel(6, 8, EYE_COLOR);
    canvas.pixel(8, 8, EYE_COLOR);
    canvas.show();
    delay(500);
    canvas.pixel(6, 8, 0x000000);
    canvas.pixel(8, 8, 0x000000);
    canvas.show();
    delay(500);
}