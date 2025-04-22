#pragma once 
#include "../animal.h"

class Antelope : public Animal {
public:
    Antelope();
    void collision(Organism* other) override;
};