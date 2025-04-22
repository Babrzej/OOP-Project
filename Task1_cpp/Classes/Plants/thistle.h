#pragma once
#include "../plant.h"

class Thistle : public Plant {
public:
    Thistle();
    ~Thistle();
    void action() override;
};
