#include "BitsUndBasteln.h"

Canvas canvas;
Ghost ghost;

int i = 0;

void setup() {}

void loop() {
    canvas.clear();
    canvas.draw(&ghost, 0xff00ef, i, i);
    canvas.show();
    delay(500);
    i++;
}