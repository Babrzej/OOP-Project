#pragma once
#include "../animal.h"

class Human : public Animal {
public:
    Human();
    void action() override;
};