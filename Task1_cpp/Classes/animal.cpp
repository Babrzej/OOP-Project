#include "animal.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative, int range)
    : Organism(strength, initiative) {
    this->range = range;
    }

    void Animal::action() {
        this->restriction = COUNT; // Reset restriction
        this->prevPosition = this->position; // Save the previous position
    
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
                    position.y -= this->range;
                    break;
                case DOWN:
                    position.y += this->range;
                    break;
                case LEFT:
                    position.x -= this->range;
                    break;
                case RIGHT:
                    position.x += this->range;
                    break;
            }
    
            // Check if the new position is valid
            if (position.x >= 0 && position.x < world->getWidth() &&
                position.y >= 0 && position.y < world->getHeight()) {
                validMove = true; // Exit the loop if the move is valid
            } else {
                // Revert to the previous position and retry
                this->position = this->prevPosition;
                this->restriction = direction; // Restrict the invalid direction
            }
            this->world->freeGrid(this); // Free the previous grid cell
        }
    }

void Animal::collision(Organism* other) {
    if(this->getStrength() >= other->getStrength()) {
        other->die();
        this->world->occupyGrid(this);        
    }
    else {
        this->die();
        return;
    }

}





