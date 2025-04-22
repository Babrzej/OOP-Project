#include "plant.h"
#include "Plants/plants.h"
#include <cstdlib>
#include <ctime>

#define CHANCE 30 // as 1 in CHANCE tries

Plant::Plant(int strength, char skin) 
    : Organism(strength, 0) {
    this->skin = skin;
}

Plant::~Plant() {}

void Plant::action() {
    this->world->freeGrid(this);
    this->sow();
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



void Plant::sow() {
    int chance = std::rand() % CHANCE;
    if(chance == 0) {
        Plant* baby;
        if(dynamic_cast<Belladonna*>(this)) {
            baby = new Belladonna;
        } else if (dynamic_cast<Grass*>(this)){
            baby = new Grass;
        } else if (dynamic_cast<Guarana*>(this)){
            baby = new Guarana;
        } else if (dynamic_cast<Hogweed*>(this)){
            baby = new Hogweed;
        } else if (dynamic_cast<Thistle*>(this)){
            baby = new Thistle;
        }
        baby->setWorld(this->world);
        baby->setPosition(this->getPosition());
        Position babyPos = this->getNewValidPosition();
        if(this->position == babyPos) {
            delete baby;
            return;
        }
        this->world->announcer.sowInfo(this);
        this->world->addOrganism(baby);
        baby->setPosition(babyPos);
        this->world->occupyGrid(baby);
    }
}
