#include "antelope.h"

#define STRENGTH 4
#define INITIATIVE 4
#define RANGE 2
#define SKIN 'A'

Antelope::Antelope() 
    : Animal(STRENGTH, INITIATIVE, RANGE, SKIN) {
    position = {3, 3};
}

Antelope::~Antelope() {}

void Antelope::collision(Organism* other) {
    if(dynamic_cast<Antelope*>(other)) {
        static_cast<Animal*>(other)->moveBack();
        this->giveBirth();
    }
    else if (std::rand() % 2 == 0) {
        Animal::fight(other);
    }
    else {
        world->announcer.fightInfo(other, this);
        Animal::move();
        world->occupyGrid(other);
        world->announcer.escapeInfo(this);
    }
}