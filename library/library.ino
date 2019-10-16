#include "Canvas.h"
#include "Ghost.h"

Canvas canvas;
Ghost ghost;

int i = 0;

void setup() {}

void loop() {
    canvas.clear();
    canvas.draw(&ghost, 0xffffff, i, i);
    canvas.show();
    delay(500);
    i++;
}