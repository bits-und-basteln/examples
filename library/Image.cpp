#include "Image.h"

Image::Image(long *points, unsigned dimX, unsigned dimY) {
    _dimX = dimX;
    _dimY = dimY;
    _points = points;
}

unsigned Image::getDimX() {
    return _dimX;
}

unsigned Image::getDimY() {
    return _dimY;
}

long Image::getPoint(unsigned x, unsigned y) {
    return _points[(_dimX * y) + x];
}