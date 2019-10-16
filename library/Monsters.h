#ifndef Monsters_h
#define Monsters_h

#include <avr/pgmspace.h>
#include "Stamp.h"

class Monsters
{
  public:
    Monsters();
    Stamp makeGhost();
};

#endif