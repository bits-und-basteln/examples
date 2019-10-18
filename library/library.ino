#include "BitsUndBasteln.h"

Canvas canvas;
Ghost ghost;

int i = 0;

void setup() {}

void loop() {
    canvas.clear();
    canvas.draw(&ghost, i, i, CYAN);
    canvas.show();
    delay(500);
    i++;
}