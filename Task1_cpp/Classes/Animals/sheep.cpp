#include "sheep.h"

#define STRENGTH 4
#define INITIATIVE 4
#define RANGE 1

Sheep::Sheep() 
    : Animal(STRENGTH, INITIATIVE, RANGE) {
    chr = 'S';
    _position = {6, 6};
}