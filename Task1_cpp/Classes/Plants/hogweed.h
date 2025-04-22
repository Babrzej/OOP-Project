#pragma once
#include "../plant.h"

class Hogweed : public Plant {
public:
    Hogweed();
    void collision(Organism* other) override;
};
