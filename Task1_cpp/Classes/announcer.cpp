#include "announcer.h"
#include "Animals/animals.h"
#include "Plants/plants.h"

Announcer::Announcer() = default;

Announcer::~Announcer() {}

void Announcer::announce() {
    for(std::string announcement : announcements) {
        std::cout << announcement << std::endl;
    }
    this->announcements.clear();
}

std::string Announcer::getType(Organism* organism) {
    if (dynamic_cast<Human*>(organism)) {
        return "Human";
    } else if (dynamic_cast<Turtle*>(organism)) {
        return "Turtle";
    } else if (dynamic_cast<Antelope*>(organism)) {
        return "Antelope";
    } else if (dynamic_cast<Fox*>(organism)) {
        return "Fox";
    } else if (dynamic_cast<Wolf*>(organism)) {
        return "Wolf";
    } else if (dynamic_cast<Sheep*>(organism)) {
        return "Sheep";
    } else if (dynamic_cast<Thistle*>(organism)) {
        return "Thistle";
    } else if (dynamic_cast<Hogweed*>(organism)) {
        return "Hogweed";
    } else if (dynamic_cast<Guarana*>(organism)) {
        return "Guarana";
    } else if (dynamic_cast<Grass*>(organism)) {
        return "Grass";
    } else if (dynamic_cast<Belladonna*>(organism)) {
        return "Belladonna";
    }
}


void Announcer::fightInfo(Organism* attacker, Organism* defender) {
    std::string info = getType(attacker) + " fights with " + getType(defender) + ".";
    announcements.push_back(info);
}

void Announcer::eatInfo(Organism* animal, Organism* plant) {
    std::string info = getType(animal) + " has eaten " + getType(plant) + ".";
    announcements.push_back(info);
}

void Announcer::killInfo(Organism* organism) {
    Animal* animal = dynamic_cast<Animal*>(organism);
    std::string info;
    if(animal) {
        info = getType(organism) + " died.";
        announcements.push_back(info);
    }
    
}

void Announcer::escapeInfo(Organism* organism) {
    std::string info = getType(organism) + " managed to escape.";
    announcements.push_back(info);
}

void Announcer::reflectInfo(Organism* organism) {
    std::string info = "Turtle reflected attack. " + getType(organism) + " moves back.";
    announcements.push_back(info);
}

void Announcer::boostInfo(Organism* organism) {
    std::string info = getType(organism) + " has eaten Guarana, strength increased by 3!";
    announcements.push_back(info);
}

void Announcer::powerInfo(std::string state) {
    std::string info = "Human's antelope's speed is " + state + "activated!";
    announcements.push_back(info); 
}

void Announcer::birthInfo(Organism* organism) {
    std::string info = "New " + getType(organism) + " has been born.";
    announcements.push_back(info);
}

void Announcer::sowInfo(Organism* organism) {
    std::string info = "New " + getType(organism) + " has been sown.";
    announcements.push_back(info);
}

void Announcer::custom(std::string custom) {
    announcements.push_back(custom);
}