#include "fox.h"
#include "../world.h"

#define STRENGTH 3
#define INITIATIVE 7
#define RANGE 1

Fox::Fox() 
    : Animal(STRENGTH, INITIATIVE, RANGE) {
    chr = 'F';
    _position = {4, 4};
}

void Fox::action() {
    // Save the previous position
    this->_prevPosition = this->_position;

    // Call the base class action() to perform the default movement
    Animal::action();

    // Check if the new position is occupied by a stronger organism
    for (Organism* organism : world->getOrganisms()) {
        if (organism->position() == this->position()) {
            // If the organism at the new position has higher strength, revert the move
            if (organism->strength() > this->strength()) {
                this->_position = this->_prevPosition; // Revert to the previous position
                return; // Exit the action
            }
        }
    }
}
