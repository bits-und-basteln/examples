#include "Canvas.h"
#include "Ghost.h"

Canvas canvas;
Ghost ghost;

int i = 0;

void setup() {}

void loop() {
    canvas.clear();
    canvas.draw(ghost, 0xffffff, 0, 0);
    canvas.show();
    delay(500);
    i++;
}