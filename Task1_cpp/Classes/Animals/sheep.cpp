#include "sheep.h"

#define STRENGTH 4
#define INITIATIVE 4
#define RANGE 1
#define SKIN 'S'

Sheep::Sheep() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    position = {3, 4};
}