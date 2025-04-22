#pragma once
#include "../animal.h"

class Human : public Animal {
public:
    Human();
    void action() override;
    int getDuration() const;
    int getCooldown() const;

private:
    void activatePower();
    void whilePowered();
    void deactivatePower();
    int duration;
    int cooldown;
};