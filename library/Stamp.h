#ifndef Stamp_h
#define Stamp_h

#include "Arduino.h"
#include <avr/pgmspace.h>

class Stamp
{
  public:
    Stamp(int dimX, int dimY, const bool* pattern);
    bool getPoint(int x, int y);
    int getDimX();
    int getDimY();
  protected:
    int indexOf(int x, int y);
  private:
    int dimX;
    int dimY;
    const bool* pattern;
};

#endif