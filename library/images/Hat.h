#ifndef Hat_h
#define Hat_h

#include <avr/pgmspace.h>
#include "../Stamp.h"

const bool hatData[] PROGMEM =
{
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
};

Stamp hat(7, 3, hatData);

#endif