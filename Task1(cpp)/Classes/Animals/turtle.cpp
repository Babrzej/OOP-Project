#include "turtle.h"

#define STRENGTH 2
#define INITIATIVE 1

Turtle::Turtle() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'T';
    position = {2, 2};
}