#include "Stamp.h"
#include <avr/pgmspace.h>

Stamp::Stamp(int dimX, int dimY) {
    _dimX = dimX;
    _dimY = dimY;
}

bool Stamp::getPoint(int x, int y) {
    return true;
}

int Stamp::getDimX() {
    return _dimX;
}

int Stamp::getDimY() {
    return _dimY;
}

int Stamp::indexOf(int x, int y) {
    return getDimX() * y + x;
}