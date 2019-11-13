#ifndef Ghost_h
#define Ghost_h

#include "Arduino.h"
#include <avr/pgmspace.h>
#include "../Stamp.h"

const bool ghostData[] PROGMEM =
{
  false, true, true, true, false, 
  true, true, true, true, true,
  true, false, true, false, true,
  true, true, true, true, true,
  true, true, true, true, true,
  true, false, true, false, true
};
Stamp ghost(5, 6, ghostData);

#endif