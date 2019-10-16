#ifndef Stamp_h
#define Stamp_h

#include "Arduino.h"

class Stamp
{
  public:
    Stamp();
    bool getPoint(unsigned x, unsigned y);
    unsigned getDimX();
    unsigned getDimY();
};

#endif