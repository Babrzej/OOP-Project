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
    Animal::move();
}

Position Fox::getNewValidPosition() {
    int drc = std::rand() % static_cast<int>(Direction::COUNT);
    Direction direction = static_cast<Direction>(drc);

    for (int i = 0; i < static_cast<int>(Direction::COUNT); i++) {
        Position newPos = getPosition();
        direction = static_cast<Direction>((direction + 1) % static_cast<int>(Direction::COUNT));
        switch (direction) {
            case UP:
                newPos.y -= this->range; // Move up
                break;
            case DOWN:
                newPos.y += this->range; // Move down
                break;
            case LEFT:
                newPos.x -= this->range; // Move left
                break;
            case RIGHT:
                newPos.x += this->range; // Move right
                break;
        }

        // Check if the new position is within bounds
        if (newPos.x >= 0 && newPos.x < this->world->getWidth() &&
            newPos.y >= 0 && newPos.y < this->world->getHeight()) {
            // Check if the grid is occupied and if the Fox can move there
            if (!this->world->isGridOccupied(newPos) ||
                this->world->getOrganismAt(newPos)->getStrength() <= this->getStrength()) {
                return newPos; // Return the valid position
            }
        }
    }

    // If no valid position is found, return the current position
    return position;
}
