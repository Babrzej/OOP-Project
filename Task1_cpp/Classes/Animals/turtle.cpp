#include "turtle.h"

#define STRENGTH 2
#define INITIATIVE 1
#define RANGE 1
#define SKIN 'T'

Turtle::Turtle() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    position = {2, 4};
}

Turtle::~Turtle() {}

void Turtle::action() {
    if (std::rand() % 4 == 0) Animal::action();
    else this->world->freeGrid(this); 
}

void Turtle::collision(Organism* other) {
    if(dynamic_cast<Turtle*>(other)) {
        static_cast<Animal*>(other)->moveBack();
        this->giveBirth();
    } 
    else if(other->getStrength() >= 5) {
        Animal::fight(other);
    }
    else {
        world->announcer.fightInfo(other, this);
        Animal* otherAnimal = dynamic_cast<Animal*>(other);
        otherAnimal->moveBack();
        world->announcer.reflectInfo(other);
    }
}