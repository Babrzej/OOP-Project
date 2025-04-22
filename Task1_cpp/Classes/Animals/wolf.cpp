#include "wolf.h"

#define STRENGTH 9
#define INITIATIVE 5
#define RANGE 1
#define SKIN 'W'

Wolf::Wolf() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    position = {7, 7};
}

Wolf::~Wolf() {}