#ifndef Image_h
#define Image_h

#include "Arduino.h"
#include <avr/pgmspace.h>

class Image
{
  public:
    Image(long *points, unsigned dimX, unsigned dimY);
    long getPoint(unsigned x, unsigned y);
    unsigned getDimX();
    unsigned getDimY();
  private:
    unsigned _dimX;
    unsigned _dimY;
    long *_points;
};

#endif