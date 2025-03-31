#include "sheep.h"

#define STRENGTH 4
#define INITIATIVE 4

Sheep::Sheep() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'S';
    _position = {6, 6};
}