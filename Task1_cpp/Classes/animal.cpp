#include "animal.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative, int range, char skin)
    : Organism(strength, initiative) {
        this->range = range;
        this->skin = skin;
}

Animal::~Animal() {}

void Animal::action() {
        this->restriction = COUNT; // Reset restriction
        this->prevPosition = this->position; // Save the previous position
    
        int drc;
        Direction direction = COUNT;

        this->world->freeGrid(this); // Free the previous grid cell

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
        }
        //this->world->announcer.moveInfo(this);
    }

void Animal::collision(Organism* other) {
    world->announcer.fightInfo(other, this); 
    if(this->getStrength() > other->getStrength()) {
        other->die();
        world->occupyGrid(this);        
    }
    else {
        this->die();
        world->occupyGrid(other);
        return;
    }


}

Position Animal::getNewValidPosition() {
    int drc = std::rand() % static_cast<int>(Direction::COUNT);
    Direction direction = static_cast<Direction>(drc);

    for(int i = 0; i < 3; i++) {
        Position newPos = getPosition();
        direction = static_cast<Direction>(direction + 1);
        direction = direction == COUNT ? static_cast<Direction>(direction + 1) : direction;
        switch (direction) {
            case UP:
                newPos.y += this->range;
                break;
            case DOWN:
                newPos.y += this->range;
                break;
            case LEFT:
                newPos.x -= this->range;
                break;
            case RIGHT:
                newPos.x += this->range;
                break;
        }
        if(!this->world->isGridOccupied(newPos)) return newPos;
        
    }
    return position;
}

void Animal::move() {
    this->prevPosition = this->position;
    this->world->freeGrid(this);
    Position newPos = getNewValidPosition();
    this->position = newPos;
    //this->world->occupyGrid(this);
}

void Animal::moveBack() {
    this->world->freeGrid(this);
    this->position = this->prevPosition;
    this->world->occupyGrid(this);
}




