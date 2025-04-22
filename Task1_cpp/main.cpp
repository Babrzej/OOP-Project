#include "Classes/classes.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    std::srand(time(0));
    Human h;
    Turtle t;
    Antelope a;
    Fox f;
    Wolf w;
    Sheep s;

    Thistle th;
    Hogweed hw;
    Guarana gu;
    Grass gr;
    Belladonna be;

    std::vector<Organism*> organisms = {&h, &t, &a, &f, &w, &s, &th, &hw, &gu, &gr, &be};
    World world(organisms);
    world.drawWorld();

    Announcer announcer;

    bool exit = false;
    while(!h.isDead()) {
        world.makeTurn();
        world.drawWorld();
        world.announce();

    }
    return 0;
}