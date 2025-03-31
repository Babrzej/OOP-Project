#include "turtle.h"

#define STRENGTH 2
#define INITIATIVE 1

Turtle::Turtle() 
    : Animal(STRENGTH, INITIATIVE) {
    chr = 'T';
    _position = {2, 2};
}

void Turtle::action() {
    if (std::rand() % 4 == 0) Animal::action();
}