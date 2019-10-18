#ifndef Lib_h
#define Lib_h

#include <BitsUndBasteln.h>

Canvas canvas;
Ghost ghost;
Hat hat;

void drawGhost(int x, int y, long color) {
    canvas.draw(&ghost, x, y, color);
}

void drawHat(int x, int y, long color) {
    canvas.draw(&hat, x, y, color);
}

#endif