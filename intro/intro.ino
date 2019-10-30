#include "Lib.h"

void setup(){};

long GHOST_COLOR = WHITE;
long HAT_COLOR = MAGENTA;
long EYE_COLOR = 0xcc0000;

void loop(){
    canvas.clear();
    drawGhost(5, 6, GHOST_COLOR);
    drawHat(4, 4, HAT_COLOR);
    canvas.show();
    delay(500);
};