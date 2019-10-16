/* https://www.brainy-bits.com/arduino-16x16-matrix-frame/ 
 Arduino 256 RGB LEDs Matrix Animation Frame 
 Using WS2812 LED Strips
 
Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...

You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/

#include <avr/pgmspace.h>  // Needed to store stuff in Flash using PROGMEM
#include "FastLED.h"       // Fastled library to control the LEDs

// How many leds are connected?
#define NUM_LEDS 256

// Define the Data Pin
#define DATA_PIN 6  // Connected to the data pin of the first LED strip

// Define the array of leds
CRGB leds[NUM_LEDS];

// Create the array of retro arcade characters and store it in Flash memory
const long DigDug01[] PROGMEM =
{
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 
0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x0066cc, 0x000000, 0x0066cc, 0x000000, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 
0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0x000000, 0x0066cc, 0x000000, 0x0066cc, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 
0x000000, 0x000000, 0x000000, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x0066cc, 0x0066cc, 0xcccccc, 0x000000, 0x000000, 
0x000000, 0xff0000, 0xff0000, 0xff0000, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0x0066cc, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000,  
0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 
0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000
};

const long DigDug02[] PROGMEM =
{
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 
0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x0066cc, 0x000000, 0x0066cc, 0x000000, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000,  
0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0x000000, 0x0066cc, 0x000000, 0x0066cc, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 
0x000000, 0x000000, 0x000000, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x0066cc, 0x0066cc, 0xcccccc, 0x000000, 0x000000, 
0x000000, 0xff0000, 0xff0000, 0xff0000, 0x0066cc, 0x0066cc, 0x0066cc, 0x0066cc, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0x0066cc, 0x0066cc, 0x0066cc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000,  
0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xcccccc, 0xcccccc, 0xcccccc, 0xcccccc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000
};

const long Qbert01[] PROGMEM =
{
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 
0x000000, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xffffcc, 0xffffcc, 0xff0033, 0xffffcc, 0xffffcc, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0xff0033, 0xff6600, 0xff6600, 0xff0033, 0xff0033, 
0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0xff0033, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0xff0033,  
0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 
0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xff6600, 0xff0033, 0xff6600, 0xff0033, 0xff6600, 0xff0033, 0xff0033, 
0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xff0033, 0x000000, 0xff0033, 0xff0033, 0x000033, 0x000033, 0xff6600, 0x000000, 
0x000000, 0xff0033, 0x000033, 0x000033, 0xff0033, 0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 0x000000,
0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 0xff0033, 0xff6600, 0xff6600, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff0033, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0x000000, 0x000000, 0x000000
};

const long Qbert02[] PROGMEM =
{
0x000000, 0x000000, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 
0x000000, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xffffff, 0xffffff, 0xff0033, 0xffffff, 0xffffff, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0xff0033, 0xff6600, 0xff6600, 0xff0033, 0x000000, 
0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0xff6600, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0xff0033, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0xff0033, 
0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 
0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xff6600, 0xff0033, 0xff6600, 0xff0033, 0xff6600, 0xff0033, 0xff0033,
0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff6600, 0xff0033, 0xff0033, 0x000000, 0xff0033, 0xff0033, 0x000000, 0x000000, 0xff6600, 0x000000, 
0x000000, 0xff0033, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0xff0033, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0xff0033, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000, 0xff0033, 0x000000, 0x000000, 0x000000,
0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0x000000, 0x000000, 0xff0033, 0xff6600, 0xff6600, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff0033, 0x000000, 0x000000, 0xff6600, 0xff6600, 0xff6600, 0xff0033, 0x000000, 0x000000, 0x000000
};

const long BombJack01[] PROGMEM =
{
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x0099ff, 0x333366, 0x333366, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 0x0099ff, 0x333366, 0x333366,
0x333366, 0x333366, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x0099ff, 0x0099ff, 0x0099ff, 0xffffff, 0xffffff, 0x0099ff, 0xffffff, 0xffffff, 0x0099ff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x0099ff, 0x0099ff, 0xffffff, 0x000000, 0x0099ff, 0x000000, 0xffffff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x0099ff, 0xffffff, 0x000000, 0x0099ff, 0x000000, 0xffffff, 0x0099ff, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0xffcc99, 0xffcc99, 0xffcc99, 0xffcc99, 0xffcc99, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0xffffff, 0xffcc99, 0xffcc99, 0xffcc99, 0xffcc99, 0xffcc99, 0xffffff, 0x333366, 0x333366, 0x333366, 0x333366,
0x333366, 0x333366, 0x333366, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x333366, 0x333366, 
0x333366, 0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x333366, 0x333366, 
0x333366, 0x333366, 0x000000, 0x000000, 0xffffff, 0x0099ff, 0x0099ff, 0x0099ff, 0xffff00, 0x0099ff, 0x0099ff, 0x0099ff, 0xffffff, 0x000000, 0x000000, 0x333366, 
0x333366, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0x333366, 0x333366, 
0x333366, 0x333366, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0x333366,  
0x333366, 0x333366, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xffffff, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x000000, 0x000000, 0x000000, 0x333366, 0x000000, 0x000000, 0x000000, 0x333366, 0x333366, 0x333366, 0x333366
};

const long BombJack02[] PROGMEM =
{
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x0099ff, 0x333366, 0x333366, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 0x0099ff, 0x333366, 0x333366, 
0x333366, 0x333366, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x0099ff, 0x0099ff, 0x0099ff, 0xffffff, 0x000000, 0x0099ff, 0x000000, 0xffffff, 0x0099ff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x0099ff, 0x0099ff, 0xffffff, 0x000000, 0x0099ff, 0x000000, 0xffffff, 0x0099ff, 0x0099ff, 0x333366, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0x000000, 0x000000, 0x333366, 0x0099ff, 0xffffff, 0xffffff, 0xffcc99, 0xffffff, 0xffffff, 0x0099ff, 0x333366, 0x000000, 0x000000, 0x333366,
0x333366, 0x000000, 0x000000, 0xff0000, 0xffcc99, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xffcc99, 0xff0000, 0x000000, 0x000000, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0xff0000, 0xff0000, 0xffffff, 0xffcc99, 0xffcc99, 0xffcc99, 0xffcc99, 0xffcc99, 0xffffff, 0xff0000, 0xff0000, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xffffff, 0x333366, 0x333366, 0x333366, 
0x333366, 0x333366, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0x333366, 0x333366, 
0x333366, 0x333366, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0x333366, 0x333366, 
0x333366, 0x333366, 0xffffff, 0xffffff, 0xffffff, 0x0099ff, 0x0099ff, 0x0099ff, 0xffff00, 0x0099ff, 0x0099ff, 0x0099ff, 0xffffff, 0xffffff, 0xffffff, 0x333366,
0x333366, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x333366, 
0x333366, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 
0x333366, 0x333366, 0x333366, 0xffffff, 0xffffff, 0xff0000, 0xff0000, 0xffffff, 0xff0000, 0xff0000, 0xffffff, 0x333366, 0xffffff, 0xffffff, 0x333366, 0x333366, 
0x333366, 0x333366, 0x333366, 0x333366, 0x333366, 0x000000, 0x000000, 0x000000, 0x333366, 0x000000, 0x000000, 0x000000, 0x333366, 0x333366, 0x333366, 0x333366
};



void setup() { 
FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);  // Init of the Fastled library
FastLED.setBrightness(10);
}

void loop() { 


// Put Qbert first frame
for(int passtime = 0; passtime < 8; passtime++) { // Display it 8 times

FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(Qbert01[i]));  // Read array from Flash
  }

FastLED.show();
delay(165);


// Put Qbert second frame
FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(Qbert02[i]));
  }

FastLED.show();
delay(165);

}


// Put DigDug first frame
for(int passtime = 0; passtime < 8; passtime++) {

FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(DigDug01[i]));
  }

FastLED.show();
delay(250);


// Put DigDug second frame
FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(DigDug02[i]));
  }

FastLED.show();
delay(250);

}


// Put BombJack first frame
for(int passtime = 0; passtime < 8; passtime++) {

FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(BombJack01[i]));
  }

FastLED.show();
delay(400);


// Put BombJack second frame
FastLED.clear();
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = pgm_read_dword(&(BombJack02[i]));
  }

FastLED.show();
delay(400);

}

}
