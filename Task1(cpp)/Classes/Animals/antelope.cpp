#include "antelope.h"

#define STRENGTH 4
#define INITIATIVE 4

Antelope::Antelope() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'A';
    position = {3, 3};
}