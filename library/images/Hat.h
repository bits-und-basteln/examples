#ifndef Hat_h
#define Hat_h

#include <avr/pgmspace.h>
#include "../Stamp.h"

const bool HatData[] PROGMEM =
{
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
};

class Hat: public Stamp
{
  public:
    Hat() 
    :Stamp(7, 3) {
    };
    bool getPoint(int x, int y) override {
        return pgm_read_byte(&(HatData[indexOf(x, y)]));
    };
};

#endif