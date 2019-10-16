#include "Canvas.h"

Canvas canvas;
int i = 0;

void setup() {}

void loop() {
    canvas.pixel(i, i, 0xffffff);
    canvas.show();
    delay(500);
    i++;
}