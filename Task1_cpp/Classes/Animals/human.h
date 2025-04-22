#pragma once
#include "../animal.h"

class Human : public Animal {
public:
    Human();
    void action() override;
private:
    void activatePower();
    void whilePowered();
    void deactivatePower();
    int duration;
    int cooldown;
};