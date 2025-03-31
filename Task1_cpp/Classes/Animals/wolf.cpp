#include "wolf.h"

#define STRENGTH 9
#define INITIATIVE 5

Wolf::Wolf() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'W';
    _position = {7, 7};
}