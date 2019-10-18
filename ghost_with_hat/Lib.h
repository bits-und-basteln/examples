#ifndef Lib_h
#define Lib_h

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

#include "../lib/Bub.h"

Canvas canvas;
Ghost ghost;
Hat hat;

void drawGhost(int x, int y, long color) {
    canvas.draw(&ghost, x, y, color);
}

void drawHat(int x, int y, long color) {
    canvas.draw(&ghost, x, y, color);
}

#endif