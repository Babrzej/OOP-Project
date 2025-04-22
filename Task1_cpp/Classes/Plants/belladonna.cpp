#include "belladonna.h"

#define STRENGTH 99
#define SKIN 'B'

Belladonna::Belladonna() 
    : Plant(STRENGTH, SKIN) {
    position = {6, 4};
}

Belladonna::~Belladonna() {}

void Belladonna::collision(Organism* other) {
    this->world->announcer.eatInfo(other, this); 
    other->die();
    this->world->occupyGrid(this);  
}