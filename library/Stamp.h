#ifndef Stamp_h
#define Stamp_h

#include "Arduino.h"
#include <avr/pgmspace.h>

class Stamp
{
  public:
    Stamp(int dimX, int dimY);
    virtual bool getPoint(int x, int y);
    int getDimX();
    int getDimY();
  protected:
    int indexOf(int x, int y);
  private:
    int _dimX;
    int _dimY;
};

#endif