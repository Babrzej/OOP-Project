#include "animal.h"
#include "Animals/animals.h"
#include <cstdlib>
#include <typeinfo>

Animal::Animal(int strength, int initiative, int range, char skin)
    : Organism(strength, initiative) {
        this->range = range;
        this->skin = skin;
}

Animal::~Animal() {}

void Animal::action() {
        this->age++;
        this->restriction = COUNT; // Reset restriction
        this->prevPosition = this->position;
        int drc;
        Direction direction = COUNT;

        this->world->freeGrid(this);

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
    if(typeid(*this) == typeid(*other)) {
        static_cast<Animal*>(other)->moveBack();
        this->giveBirth();
    }
    else {
        this->fight(other);
    }

}

void Animal::move() {
    this->prevPosition = this->position;
    this->world->freeGrid(this);
    Position newPos = getNewValidPosition();
    this->position = newPos;
}

void Animal::moveBack() {
    this->world->freeGrid(this);
    this->position = this->prevPosition;
    this->world->occupyGrid(this);
}

void Animal::fight(Organism* other) {
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
void Animal::giveBirth() {
    Animal* baby;
    if(dynamic_cast<Antelope*>(this)) {
        baby = new Antelope;
    } else if (dynamic_cast<Fox*>(this)){
        baby = new Fox;
    } else if (dynamic_cast<Sheep*>(this)){
        baby = new Sheep;
    } else if (dynamic_cast<Turtle*>(this)){
        baby = new Turtle;
    } else if (dynamic_cast<Wolf*>(this)){
        baby = new Wolf;
    }
    baby->setWorld(this->world);
    baby->setPosition(this->getPosition());
    Position babyPos = this->getNewValidPosition();
    if(this->position == babyPos) {
        delete baby;
        return;
    }
    this->world->announcer.birthInfo(this);
    this->world->addOrganism(baby);
    baby->setPosition(babyPos);
    this->world->occupyGrid(baby);
}



