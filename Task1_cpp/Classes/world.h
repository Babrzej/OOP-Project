#pragma once
#include "position.h"
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
    void kill(Organism* organism); // Method to remove an organism
    void freeGrid(Organism* organism);   // Free a grid cell based on organism
    void occupyGrid(Organism* organism); // Occupy a grid cell based on organism
    bool isGridOccupied(Position Pos);

    int width() const;  // Inner width
    int height() const; // Inner height

private:
    std::vector<Organism*> organisms;
    static const int _width = 8, _height = 8; // Inner dimensions (excluding borders)
    Grid grid[_width][_height];
};
