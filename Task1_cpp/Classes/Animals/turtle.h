#pragma once 
#include "../animal.h"

class Turtle : public Animal {
public:
    Turtle();
    void action() override;
    void collision(Organism* other) override;
};