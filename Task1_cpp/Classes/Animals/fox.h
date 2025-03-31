#pragma once 
#include "../animal.h"

class Fox : public Animal {
public:
    Fox();
    void action() override;
};