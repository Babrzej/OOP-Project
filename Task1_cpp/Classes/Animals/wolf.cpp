#include "wolf.h"

#define STRENGTH 9
#define INITIATIVE 5
#define RANGE 1

Wolf::Wolf() 
    : Animal(STRENGTH, INITIATIVE, RANGE) {
    chr = 'W';
    position = {7, 7};
}