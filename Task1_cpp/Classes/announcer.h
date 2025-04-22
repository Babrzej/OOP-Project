#pragma once
#include <iostream>
#include <vector>
#include "position.h"

class Organism;

class Announcer {
private:
    std::vector<std::string> announcements;
public:
    Announcer();
    void announce();
    std::string getType(Organism* organsim);
    // void moveInfo(Organism* organism);
    void fightInfo(Organism* attacker, Organism* defender);
    void eatInfo(Organism* animal, Organism* plant);
    void killInfo(Organism* organism);
    void escapeInfo(Organism* organism);
    void reflectInfo(Organism* organism);
    void boostInfo(Organism* organism);
    void powerInfo(std::string state);


};