#pragma once 
#include "../animal.h"

class Fox : public Animal {
public:
    Fox();
    ~Fox();
    void action() override;
    Position getNewValidPosition() override;
};