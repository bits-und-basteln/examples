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

int delayval = 500; // delay for half a second

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

void setup() {
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // This initializes the NeoPixel library.
}


void loop() {

    bool foo[16][16] = {
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
      {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true}
    };
    int r = 50;
    int g = 50;
    int b = 50;


    showMonochromeArray(foo, r, g, b);
    delay(500);

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

void light(int row, int column, int r, int g, int b) {
  int i;
  if (row%2 == 0) {
    i = (row * 16) + (15 - column);
  } else {
    i = (row * 16) + column;
  }
  pixels.setPixelColor(i, pixels.Color(r ,g, b));
}
