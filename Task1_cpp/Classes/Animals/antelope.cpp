#include "antelope.h"

#define STRENGTH 4
#define INITIATIVE 4
#define RANGE 2

Antelope::Antelope() 
    : Animal(STRENGTH, INITIATIVE, RANGE) {
    chr = 'A';
    position = {3, 3};
}