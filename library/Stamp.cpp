#include "Stamp.h"
#include <avr/pgmspace.h>

Stamp::Stamp(int dimX, int dimY, const bool* pattern) {
    this->dimX = dimX;
    this->dimY = dimY;
    this->pattern = pattern;
}

int Stamp::getDimX() {
    return this->dimX;
}

int Stamp::getDimY() {
    return this->dimY;
}

bool Stamp::getPoint(int x, int y) {
    return pgm_read_byte(&(this->pattern[indexOf(x, y)]));
}

int Stamp::indexOf(int x, int y) {
    return getDimX() * y + x;
}