#pragma once
#include <iostream>
#include <vector>
#include "position.h"

class Organism;

class Announcer {
private:
    std::vector<std::string> announcements;
    std::string getType(Organism* organsim);
public:
    Announcer();
    ~Announcer();
    void announce();
    void fightInfo(Organism* attacker, Organism* defender);
    void eatInfo(Organism* animal, Organism* plant);
    void killInfo(Organism* organism);
    void escapeInfo(Organism* organism);
    void reflectInfo(Organism* organism);
    void boostInfo(Organism* organism);
    void powerInfo(std::string state);
    void birthInfo(Organism* organism);
    void sowInfo(Organism* organism);

    void custom(std::string custom);
};