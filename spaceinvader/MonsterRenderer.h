// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <math.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      256

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

bool invader[8][11] = {
  {false, false, true, false, false, false, false, false, true, false, false},
  {false, false, false, true, false, false, false, true, false, false, false},
  {false, false, true, true, true, true, true, true, true, false, false},
  {false, true, true, false, true, true, true, false, true, true, false},
  {true, true, true, true, true, true, true, true, true, true, true},
  {true, false, true, true, true, true, true, true, true, false, true},
  {true, false, true, false, false, false, false, false, true, false, true},
  {false, false, false, true, true, false, true, true, false, false, false}
 };

// 6x5
 bool ghost[30] = {
  false, true, true, true, false, 
  true, true, true, true, true,
  true, false, true, false, true,
  true, true, true, true, true,
  true, true, true, true, true,
  true, false, true, false, true
 };

 void clear() {
     for (int i = 0; i < 256; i++) {
        pixels.setPixelColor(i, pixels.Color(0 ,0, 0));
     }
 }

int flatten(int x, int y, int dimX, int dimY) {
  return (dimX * y) + x;
}
 
int canvasCoord(int x, int y) {
  if (x >= 16) {
    x = x%16;
  }
  if (y >= 16) {
    y = y%16;
  }
  int n;
  if (x%2 == 0) {
    n = (x * 16) + (15 - y);
  } else {
    n = (x * 16) + y;
  }
  return n;
}

void light(int row, int column, int r, int g, int b) {
  pixels.setPixelColor(canvasCoord(row, column), pixels.Color(r ,g, b));
}

 void showMonochromeArray(bool leds[16][16], int r, int g, int b) {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      if (leds[i][j]) {
        light(i, j, r, g, b);
      } else {
        light(i, j, 0, 0, 0);
      }
    }
  }
  pixels.show();
}

void clearCanvas() {
  for (int i = 0; i < 256; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}
  
void draw(bool *image, int nRows, int nCols, int offX, int offY, int r, int g, int b) {
  for (int i = 0; i < nRows; i++) {
    for (int j = 0; j < nCols; j++) {
      if (image[flatten(i, j, nRows, nCols)]) { 
        light(i+offX, j+offY, r, g, b);
      }
    }
  }
  pixels.show();
}

void drawGhost(int x, int y, int r, int g, int b) {
  draw(&ghost[0], 5, 6, x, y, r, g, b);
}

