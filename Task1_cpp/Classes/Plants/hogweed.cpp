#include "hogweed.h"

#define STRENGTH 10
#define SKIN 'H'

Hogweed::Hogweed() 
    : Plant(STRENGTH, SKIN) {
    position = {6, 3};
}

void Hogweed::collision(Organism* other) {
    this->world->announcer.eatInfo(other, this); 
    other->die();
    this->world->occupyGrid(this);  
}
