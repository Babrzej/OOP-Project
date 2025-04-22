#pragma once 
#include "../plant.h"

class Belladonna : public Plant {
public:
    Belladonna();
    void collision(Organism* other) override;
};