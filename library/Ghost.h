#ifndef Ghost_h
#define Ghost_h

#include "Arduino.h"
#include <avr/pgmspace.h>

const bool GhostData[] PROGMEM =
{
  false, true, true, true, false, 
  true, true, true, true, true,
  true, false, true, false, true,
  true, true, true, true, true,
  true, true, true, true, true,
  true, false, true, false, true
};

class Ghost
{
  public:
    Ghost() {};
    bool getPoint(unsigned x, unsigned y) const {
        return pgm_read_byte(&(GhostData[(5 * y) + x]));
    };
    unsigned getDimX() const {
        return 5;
    };
    unsigned getDimY() const {
        return 6;
    };
};

#endif