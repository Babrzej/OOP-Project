#pragma once 
#include "organism.h"
#include "world.h"
#include <cstdlib>

class Plant : public Organism{
public: 
    // constructors
    Plant(int strength, char skin);
    ~Plant();
    // other methods
    void action() override;
    void collision(Organism* other) override;
};
