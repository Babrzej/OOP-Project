#include "plant.h"
#include <cstdlib>
#include <ctime>

Plant::Plant(int strength) 
    : Organism(strength, 0) {}


void Plant::action() {
    int b = 0;
    b++;
}
    


void Plant::collision(Organism* other) {
    int a; 
    a++;
}

Plant::~Plant() {}

