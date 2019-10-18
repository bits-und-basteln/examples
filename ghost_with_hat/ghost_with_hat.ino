#include "Lib.h"

void setup(){};

long GHOST_COLOR = CYAN;
long HAT_COLOR = MAGENTA;
long EYE_COLOR = GREEN;

void loop(){
    canvas.clear();
    drawGhost(5, 6, GHOST_COLOR);
    drawHat(4, 0, HAT_COLOR);
    canvas.show();
    delay(500);

    canvas.clear();
    drawGhost(5, 6, GHOST_COLOR);
    drawHat(4, 1, HAT_COLOR);
    canvas.show();
    delay(500);

    canvas.clear();
    drawGhost(5, 6, GHOST_COLOR);
    drawHat(4, 2, HAT_COLOR);
    canvas.show();
    delay(500);

    canvas.clear();
    drawGhost(5, 6, GHOST_COLOR);
    drawHat(4, 3, HAT_COLOR);
    canvas.show();
    delay(500);

    canvas.clear();
    drawGhost(5, 6, GHOST_COLOR);
    drawHat(4, 4, HAT_COLOR);
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
};