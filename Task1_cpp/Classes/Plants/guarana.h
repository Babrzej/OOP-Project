#pragma once
#include "../plant.h"

class Guarana : public Plant {
public:
    Guarana();
    ~Guarana();
    void collision(Organism* other) override;
};
