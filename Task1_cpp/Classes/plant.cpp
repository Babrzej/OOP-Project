#include "plant.h"
#include <cstdlib>
#include <ctime>

Plant::Plant(int strength, char skin) 
    : Organism(strength, 0) {
        this->skin = skin;
    }


void Plant::action() {
    this->world->freeGrid(this);
}
    


void Plant::collision(Organism* other) {
    this->world->announcer.eatInfo(other, this); 
    if(this->getStrength() > other->getStrength()) {
        other->die();
        this->world->occupyGrid(this);      
    }
    else {
        this->die();
        this->world->occupyGrid(other);
        return;
    }
}

Plant::~Plant() {}

