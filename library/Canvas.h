#ifndef Canvas_h
#define Canvas_h

#include "Arduino.h"
#include <avr/pgmspace.h>  // Needed to store stuff in Flash using PROGMEM
#include "FastLED.h"       // Fastled library to control the LEDs
#include "Stamp.h"

class Canvas
{
  public:
    Canvas();
    void setBrightness(int brightness);
    void pixel(int x, int y, long color);
    void draw(Stamp *stamp, long color, int x, int y);
    void show();
    void clear();
};


#endif