#include "Canvas.h"
#include "Monsters.h"

Canvas canvas;
Monsters monsters;

int i = 0;

void setup() {}

void loop() {
    canvas.clear();
    canvas.draw(monsters.makeGhost(), 0xffffff, 0, 0);
    canvas.show();
    delay(500);
    i++;
}