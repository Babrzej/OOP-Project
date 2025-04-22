#pragma once 
#include "../animal.h"

class Antelope : public Animal {
public:
    Antelope();
    ~Antelope();
    void collision(Organism* other) override;
};