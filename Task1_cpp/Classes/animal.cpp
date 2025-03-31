#include "animal.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative)
    : Organism(strength, initiative) {}

    void Animal::action() {
        this->restriction = COUNT; // Reset restriction
        this->_prevPosition = this->_position; // Save the previous position
    
        int drc;
        Direction direction = COUNT;
    
        // Retry until a valid position is found
        bool validMove = false;
        while (!validMove) {
            // Generate a random direction that is not restricted
            while (direction == this->restriction) { 
                drc = std::rand() % static_cast<int>(Direction::COUNT);
                direction = static_cast<Direction>(drc);
            }
    
            // Move the animal based on the chosen direction
            switch (direction) {
                case UP:
                    _position.y -= 1;
                    break;
                case DOWN:
                    _position.y += 1;
                    break;
                case LEFT:
                    _position.x -= 1;
                    break;
                case RIGHT:
                    _position.x += 1;
                    break;
            }
    
            // Check if the new position is valid
            if (_position.x >= 0 && _position.x < world->width() &&
                _position.y >= 0 && _position.y < world->height()) {
                validMove = true; // Exit the loop if the move is valid
            } else {
                // Revert to the previous position and retry
                this->_position = this->_prevPosition;
                this->restriction = direction; // Restrict the invalid direction
            }
        }
    }

void Animal::collision(Organism* other) {

}




