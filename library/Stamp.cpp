#include "Stamp.h"
#include <avr/pgmspace.h>

Stamp::Stamp(const bool points[], unsigned dimX, unsigned dimY) {
    _dimX = dimX;
    _dimY = dimY;
    _points = points;
}

unsigned Stamp::getDimX() {
    return _dimX;
}

unsigned Stamp::getDimY() {
    return _dimY;
}

bool Stamp::getPoint(unsigned x, unsigned y) {
    return pgm_read_dword(_points[(_dimX * y) + x]);
}