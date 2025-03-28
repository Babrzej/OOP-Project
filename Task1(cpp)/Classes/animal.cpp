#include "animal.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative, int pX, int pY, World* world)
    : Organism(strength, initiative, pX, pY, world) {
    chr = 'H'; // Set the character representation for Human
}
void Animal::action() {

    int drc = std::rand() % static_cast<int>(Direction::COUNT);
    Direction direction = static_cast<Direction>(drc);

    switch(direction) {
        case UP:
        this->pY -= 1;
        case DOWN:
        this->pY += 1;
        case LEFT:
        this->pX -= 1;
        case RIGHT:
        this->pX += 1;
    }
}

void Animal::collision() {

}



