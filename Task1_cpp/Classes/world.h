#pragma once
#include "position.h"
#include "announcer.h"
#include <algorithm>
#include <vector>
class Organism; // Forward declaration of Organism

class World {
    public:
    typedef struct {
        Organism* organism = nullptr;
        bool occupied = false;
    } Grid;
    World(std::vector<Organism*> organisms);
    void makeTurn();
    void drawWorld();
    std::vector<Organism*> getOrganisms();
    void kill();                         // Method to remove organisms
    void freeGrid(Organism* organism);   // Free a grid cell based on organism
    void occupyGrid(Organism* organism); // Occupy a grid cell based on organism
    bool isGridOccupied(Position Pos);

    int getWidth() const;  // Inner width
    int getHeight() const; // Inner height

    void sortOrganisms();
    Organism* getOrganismAt(Position position);
    void announce();

    Announcer announcer;

private:
    std::vector<Organism*> organisms;
    static const int width = 30, height = 12; // Inner dimensions (excluding borders)
    Grid grid[width][height];
};
