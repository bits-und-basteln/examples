#ifndef Stamp_h
#define Stamp_h

#include "Arduino.h"
#include <avr/pgmspace.h>

class Stamp
{
  public:
    Stamp(const bool points[], unsigned dimX, unsigned dimY);
    bool getPoint(unsigned x, unsigned y);
    unsigned getDimX();
    unsigned getDimY();
  private:
    unsigned _dimX;
    unsigned _dimY;
    const bool *_points;
};

#endif