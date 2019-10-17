#ifndef Ghost_h
#define Ghost_h

#include "Arduino.h"
#include <avr/pgmspace.h>
#include "../Stamp.h"

const bool GhostData[] PROGMEM =
{
  false, true, true, true, false, 
  true, true, true, true, true,
  true, false, true, false, true,
  true, true, true, true, true,
  true, true, true, true, true,
  true, false, true, false, true
};

class Ghost: public Stamp
{
  public:
    Ghost() 
    :Stamp(5, 6) {
    };
    bool getPoint(int x, int y) override {
        return pgm_read_byte(&(GhostData[indexOf(x, y)]));
    };
};

#endif