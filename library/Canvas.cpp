#include "Canvas.h"
#include "Arduino.h"
#include "FastLED.h"  // Fastled library to control the LEDs
#include "Stamp.h"

// How many leds are connected?
#define NUM_LEDS 256

// Define the Data Pin
#define DATA_PIN 6  // Connected to the data pin of the first LED strip

// Define the array of leds
CRGB leds[NUM_LEDS];

Canvas::Canvas() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds,
                                      NUM_LEDS);  // Init of the Fastled library
  FastLED.setBrightness(13);
}

void Canvas::show() { FastLED.show(); }

void Canvas::clear() { FastLED.clear(); }

void Canvas::setBrightness(int brightness) {
  FastLED.setBrightness(brightness);
}

void Canvas::draw(Stamp *stamp, int x, int y, long color) {
  for (int i = 0; i < stamp->getDimX(); i++) {
    for (int j = 0; j < stamp->getDimY(); j++) {
      if (stamp->getPoint(i, j)) {
        pixel(i + x, j + y, color);
      }
    }
  }
}

void Canvas::pixel(int x, int y, long color) {
  if (x >= 16) {
    x = x % 16;
  }
  if (y >= 16) {
    y = y % 16;
  }
  int i;
  if (x % 2 != 0) {
    i = (x * 16) + (15 - y);
  } else {
    i = (x * 16) + y;
  }
  leds[i] = color;
}