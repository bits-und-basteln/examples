#include "Monsters.h"
#include "Stamp.h"

const long Ghost[] =
{
  false, true, true, true, false, 
  true, true, true, true, true,
  true, false, true, false, true,
  true, true, true, true, true,
  true, true, true, true, true,
  true, false, true, false, true
};

Monsters::Monsters() {}

Stamp Monsters::makeGhost() {
    Stamp ghost(Ghost, 5, 6);
    return ghost;
}