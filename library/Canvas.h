#ifndef Canvas_h
#define Canvas_h

#include "Arduino.h"
#include <avr/pgmspace.h>  // Needed to store stuff in Flash using PROGMEM
#include "FastLED.h"       // Fastled library to control the LEDs

class Canvas
{
  public:
    Canvas();
    void pixel(int x, int y, long color);
    void show();
    void clear();
};


#endif