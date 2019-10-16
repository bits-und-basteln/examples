#include "MonsterRenderer.h"

void setup() {
    #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
    #endif

    pixels.begin(); // This initializes the NeoPixel library.    
}

int i = 0;

void loop() {
    clearCanvas();
    drawGhost(0, i, 0, 0, 15);
    i++;
    delay(500);
}
