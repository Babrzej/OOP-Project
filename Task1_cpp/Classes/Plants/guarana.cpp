#include "guarana.h"

#define STRENGTH 0
#define SKIN 'G'

#define POWER 3

Guarana::Guarana() 
    : Plant(STRENGTH, SKIN) {
    position = {2, 7};
}

Guarana::~Guarana() {}

void Guarana::collision(Organism* other) {
    world->announcer.boostInfo(other);
    this->die();
    other->setStrength(other->getStrength() + POWER);
    this->world->occupyGrid(other);
}
