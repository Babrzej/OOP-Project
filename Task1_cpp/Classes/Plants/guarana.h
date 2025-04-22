#pragma once
#include "../plant.h"

class Guarana : public Plant {
public:
    Guarana();
    void collision(Organism* other) override;
};
