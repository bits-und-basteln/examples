// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      256

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

// Jock Stick pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

// directions
enum { none, up, down, left, right};

// start state
int x = 8;  
int y = 8;
int direction = none;
bool clear = false;
char input;
int r;
int g;
int b;

int renderCount = 0;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  // setup serial input
  Serial.begin(9600);

  // setup digital input pin
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  // setup neopixel
  pixels.begin();

  changeColor();
  light(x,y,r,g,b);
  pixels.show();
}

void changeColor() {
  r = random(1,5);
  g = random(1,5);
  b = random(1,5);
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

int isButtonPressed() {
  return !digitalRead(SW_pin);
}

int readX() {
  return analogRead(X_pin);
} 

int readY() {
  return analogRead(Y_pin);
}

void moveUp() {
  x = (x + 1) % 16;
}

void moveDown() {
  x = x > 1 ? x - 1 : 15;
}

void moveLeft() {
   y = (y + 1) % 16;
}

void moveRight() {
  y = y > 1 ? y - 1 : 15;
}

void reset() {
  direction = 0;
  pixels.clear();
  clear = true;
}

void handleStickInput() {
  if (isButtonPressed()) {
    // set random color
    reset();
  }

  int xValue = readX();
  if (xValue <= 520) {
    direction = left;
  } else if (xValue >= 540) {
    direction = right;
  }

  int yValue = readY();
  if (yValue <= 520) { 
    direction = up;
  } else if (yValue >= 540) {
    direction = down;
  }
}

void updatePixelPositon() {
  switch (direction) {
    case up:
      moveUp();
      break;
    case down:
      moveDown();
      break;
    case left:
      moveLeft();
      break;
    case right:
      moveRight();
      break;      
  }
}

void handleSerialInput() {

  // look for the next character in the incoming serial stream:
  if (Serial.available() > 0) {
      input = Serial.read();
  }

  switch (input) {
    case 'w':
        direction = up;
        break;
    case 's':
        direction = down;
        break;
    case 'a':
        direction = left;
        break;
    case 'd':
        direction = right;
        break;
    // reset    
    case 'g':
        reset();
        break;

  }
}

void render() {
      if (!clear) {
        light(x,y,r,g,b);
      } else {
        clear = false;
      } 
      pixels.show(); // This sends the updated pixel color to the hardware.
}

void controllerlog() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
}

void loop() {
    handleStickInput();
    updatePixelPositon();
    if (direction) {
      changeColor();  
    }  
    render();
    delay(200);
}