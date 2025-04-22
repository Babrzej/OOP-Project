#include "thistle.h"

#define STRENGTH 0
#define SKIN 't'

Thistle::Thistle() 
    : Plant(STRENGTH, SKIN) {
    position = {5, 3};
}
