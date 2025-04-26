#include "world.h"
#include "organism.h"
#include "Animals/animals.h"
#include "Plants/plants.h"
#include <iostream>

World::World() {}

World::World(std::vector<Organism*> organisms) 
    : organisms(organisms) {
    for(Organism* organism : organisms) {
        organism->setWorld(this);
        organism->setPosition(organism->getRandomValidPosition());
        this->occupyGrid(organism);
    }
}

World::World(const std::string& filename) {
    std::vector<Organism*> loadedOrganisms = loadFromFile(filename);
    
    for (Organism* organism : loadedOrganisms) {
        organism->setWorld(this);
        organisms.push_back(organism);
        this->occupyGrid(organism);
    }
}

World::~World() {
    for (Organism* organism : organisms) {
        delete organism;
    }
}

int World::getHeight() const {
    return this->height;
}

int World::getWidth() const {
    return this->width;
}
void World::drawWorld() {
    system("cls");
    std::cout << "BLAZEJ PITULA S203549 - Organism Simulation" << std::endl;
    std::cout << "Move with arrows, 'p' to use a Power" << std::endl;
    std::cout << "'q' to quit, 's' to save and quit" << std::endl;
    // Draw the top border
    for (int x = 0; x < width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;

    // Draw the middle rows
    for (int y = 0; y < height; y++) {
        std::cout << '*'; // Left border
        for (int x = 0; x < width; x++) {
            if (grid[x][y].occupied && !grid[x][y].organism->isDead()) {
                grid[x][y].organism->draw(); // Draw the organism
            } else {
                std::cout << ' '; // Empty space
            }
        }
        std::cout << '*'; // Right border
        std::cout << std::endl;
    }

    // Draw the bottom border
    for (int x = 0; x < width + 2; x++) { // Add 2 for borders
        std::cout << '*';
    }
    std::cout << std::endl;
}

void World::makeTurn() {
    exitCondition();
    sortOrganisms();
    for(Organism* organism : organisms) {
        organism->action();
        Position pos = organism->getPosition();
        if(grid[pos.x][pos.y].occupied && grid[pos.x][pos.y].organism != organism) {
            Organism* other = grid[organism->getPosition().x][organism->getPosition().y].organism;
            other->collision(organism);
        }
        else {
            this->occupyGrid(organism);
        }
        this->kill();
        
    }
    
}

void World::exitCondition() {
    for(Organism* organism : organisms) {
        if(dynamic_cast<Human*>(organism)) return;
    }
    std::exit(0);
}

std::vector<Organism*> World::getOrganisms() {
    return this->organisms;
}

void World::kill() {
    for (auto it = organisms.begin(); it != organisms.end(); ++it) {
        if ((*it)->isDead()) {
            organisms.erase(it);
            break;
        }
    }
}

void World::freeGrid(Organism* organism) {
    Position pos = organism->getPosition();
    grid[pos.x][pos.y].organism = nullptr;
    grid[pos.x][pos.y].occupied = false;
}

void World::occupyGrid(Organism* organism) {
    Position pos = organism->getPosition();
    grid[pos.x][pos.y].organism = organism;
    grid[pos.x][pos.y].occupied = true;
}

bool World::isGridOccupied(Position pos) {
    if(grid[pos.x][pos.y].occupied) return true;
    return false;
}

void World::sortOrganisms() {
    for(Organism* organism : organismsToAdd) {
        organisms.push_back(organism);
    }
    organismsToAdd.clear();
    std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        if (a->getInitiative() != b->getInitiative()) {
            return a->getInitiative() > b->getInitiative();
        }
        return a->getAge() > b->getAge();
    });
}

Organism* World::getOrganismAt(Position position) {
    return grid[position.x][position.y].organism;
}

void World::addOrganism(Organism* organism) {
    organismsToAdd.push_back(organism);
}

void World::announce() {
    this->announcer.announce();
}

void World::save(const std::string& filename) {
    std::ofstream file(filename);

    file << organisms.size() << std::endl;

    for (Organism* organism : organisms) {
        std::string type;
        if (dynamic_cast<Human*>(organism)) type = "Human";
        else if (dynamic_cast<Turtle*>(organism)) type = "Turtle";
        else if (dynamic_cast<Antelope*>(organism)) type = "Antelope";
        else if (dynamic_cast<Fox*>(organism)) type = "Fox";
        else if (dynamic_cast<Wolf*>(organism)) type = "Wolf";
        else if (dynamic_cast<Sheep*>(organism)) type = "Sheep";
        else if (dynamic_cast<Thistle*>(organism)) type = "Thistle";
        else if (dynamic_cast<Hogweed*>(organism)) type = "Hogweed";
        else if (dynamic_cast<Guarana*>(organism)) type = "Guarana";
        else if (dynamic_cast<Grass*>(organism)) type = "Grass";
        else if (dynamic_cast<Belladonna*>(organism)) type = "Belladonna";

        file << type << " "
             << organism->getPosition().x << " " << organism->getPosition().y << " "
             << organism->getPrevPosition().x << " " << organism->getPrevPosition().y << " "
             << organism->getStrength() << " "
             << organism->getInitiative() << " "
             << organism->getRange() << " "
             << organism->getAge();

        if (type == "Human") {
            Human* human = static_cast<Human*>(organism);
            file << " " << human->getDuration() << " " << human->getCooldown();
        }
        file << std::endl;
    }

    file.close();
}

std::vector<Organism*> World::loadFromFile(const std::string& filename) {
    std::vector<Organism*> loadedOrganisms;
    std::ifstream file(filename);

    int organismCount;
    file >> organismCount;

    for (int i = 0; i < organismCount; i++) {
        std::string type;
        int posX, posY, prevPosX, prevPosY, strength, initiative, range, age;
        
        file >> type >> posX >> posY >> prevPosX >> prevPosY >> strength >> initiative >> range >> age;

        Organism* organism = nullptr;
        
        if (type == "Human") {
            int duration, cooldown;
            file >> duration >> cooldown;
            
            Human* human = new Human();
            human->setDuration(duration);
            human->setCooldown(cooldown);
            organism = human;
        }
        else if (type == "Turtle") {
            organism = new Turtle();
        }
        else if (type == "Antelope") {
            organism = new Antelope();
        }
        else if (type == "Fox") {
            organism = new Fox();
        }
        else if (type == "Wolf") {
            organism = new Wolf();
        }
        else if (type == "Sheep") {
            organism = new Sheep();
        }
        else if (type == "Thistle") {
            organism = new Thistle();
        }
        else if (type == "Hogweed") {
            organism = new Hogweed();
        }
        else if (type == "Guarana") {
            organism = new Guarana();
        }
        else if (type == "Grass") {
            organism = new Grass();
        }
        else if (type == "Belladonna") {
            organism = new Belladonna();
        }
        else {
            continue;
        }

        if (organism) {
            organism->setPosition({posX, posY});
            organism->setPrevPosition({prevPosX, prevPosY});
            organism->setStrength(strength);
            organism->setInitiative(initiative);
            organism->setRange(range);
            organism->setAge(age);
            loadedOrganisms.push_back(organism);
        }
    }

    file.close();
    return loadedOrganisms;
}
