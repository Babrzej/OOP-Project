#include "fox.h"
#include "../world.h"

#define STRENGTH 3
#define INITIATIVE 7
#define RANGE 1

Fox::Fox() 
    : Animal(STRENGTH, INITIATIVE, RANGE) {
    chr = 'F';
    position = {4, 4};
}

void Fox::action() {
    // Save the previous position
    this->prevPosition = this->position;

    // Call the base class action() to perform the default movement
    Animal::action();

    // Check if the new position is occupied by a stronger organism
    for (Organism* organism : world->getOrganisms()) {
        if (organism->getPosition() == this->getPosition()) {
            // If the organism at the new position has higher strength, revert the move
            if (organism->getStrength() > this->getStrength()) {
                this->position = this->prevPosition; // Revert to the previous position
                return; // Exit the action
            }
        }
    }
}
