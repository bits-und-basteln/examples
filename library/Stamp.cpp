#include "Stamp.h"

Stamp::Stamp(bool points[], unsigned dimX, unsigned dimY) {
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
    return _points[(_dimX * y) + x];
}