#include "animal.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative)
    : Organism(strength, initiative) {}

void Animal::action() {

    int drc = std::rand() % static_cast<int>(Direction::COUNT);
    Direction direction = static_cast<Direction>(drc);

    switch(direction) {
        case UP:
        position.y -= 1;
        case DOWN:
        position.y += 1;
        case LEFT:
        position.x -= 1;
        case RIGHT:
        position.x += 1;
    }
}

void Animal::collision() {

}



