#pragma once
#include "../animal.h"

class Human : public Animal {
public:
    Human();
    ~Human();
    void action() override;
    int getDuration() const;
    int getCooldown() const;
    void setDuration(int duration);
    void setCooldown(int cooldown);
    void passKey(int key);

private:
    void activatePower();
    void whilePowered();
    void deactivatePower();
    int duration;
    int cooldown;
    int key;
};