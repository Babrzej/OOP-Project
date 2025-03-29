#include "animal.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative)
    : Organism(strength, initiative) {}

void Animal::action() {

    this->prevPosition = this->position;

    int drc = std::rand() % static_cast<int>(Direction::COUNT);
    Direction direction = static_cast<Direction>(drc);

    switch(direction) {
        case UP:
        position.y -= 1;
        break;
        case DOWN:
        position.y += 1;
        break;
        case LEFT:
        position.x -= 1;
        break;
        case RIGHT:
        position.x += 1;
        break;
    }
}

void Animal::collision() {

}

void Animal::moveBack() {
    this->position = this->prevPosition;
}



