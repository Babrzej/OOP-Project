#include "fox.h"
#include "../world.h"

#define STRENGTH 3
#define INITIATIVE 7
#define RANGE 1
#define SKIN 'F'

Fox::Fox() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    position = {4, 3};
}

void Fox::action() {
    Animal::action();
}
