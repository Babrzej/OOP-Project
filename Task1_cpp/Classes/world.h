#pragma once
#include "position.h"
#include "announcer.h"
#include <algorithm>
#include<fstream>
#include <vector>

#define WIDTH 30
#define HEIGHT 12

class Organism;

class World {
    public:
    typedef struct {
        Organism* organism = nullptr;
        bool occupied = false;
    } Grid;
    World();
    World(std::vector<Organism*> organisms);
    World(const std::string& filename);
    ~World();
    void makeTurn();
    void drawWorld();
    std::vector<Organism*> getOrganisms();
    void kill();                         // Method to remove organisms
    void freeGrid(Organism* organism);   
    void occupyGrid(Organism* organism); 
    bool isGridOccupied(Position Pos);

    int getWidth() const;  // Inner width
    int getHeight() const; // Inner height

    void exitCondition();
    void sortOrganisms();
    Organism* getOrganismAt(Position position);
    void addOrganism(Organism* organism);

    void announce();
    Announcer announcer;

    void save(const std::string& filename);
    std::vector<Organism*> loadFromFile(const std::string& filename);

private:
    std::vector<Organism*> organisms;
    std::vector<Organism*> organismsToAdd;
    static const int width = WIDTH, height = HEIGHT;
    Grid grid[width][height];
};
