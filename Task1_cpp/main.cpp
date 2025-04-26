#include "Classes/classes.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <conio.h>

#define KEY_q 113
#define KEY_p 112
#define KEY_s 115

int main() {
    std::srand(time(0));
    Human h;
    Turtle t1, t2, t3;
    Antelope a1, a2, a3;
    Fox f1, f2, f3;
    Wolf w1, w2, w3;
    Sheep s1, s2, s3;

    Thistle th1, th2, th3;
    Hogweed hw1, hw2, hw3;
    Guarana gu1, gu2, gu3;
    Grass gr1, gr2, gr3;
    Belladonna be1, be2, be3;

    Sheep sheep[30];

    std::vector<Organism*> organisms = {&h, &t1, &a1, &f1, &w1, &s1, &th1, &hw1, &gu1, &gr1, &be1, &t2, &a2, &f2, &w2, &s2, &th2, &hw2, &gu2, &gr2, &be2, &t3, &a3, &f3, &w3, &s3, &th3, &hw3, &gu3, &gr3, &be3};
    // for(Sheep& shep : sheep) {
    //     organisms.push_back(&shep);
    // }
    World* world;
    char input;
    std::cout << "Enter 'l' to load a saved state or anything else to get new simulation: ";
    std::cin>> input;
    if(input == 'l') {
        world = new World("save.txt");
    } else {
        world = new World(organisms);
    }
    world->drawWorld();

    while(true) {
        int key = _getch();
        switch(key) {
            case KEY_q:
                std::exit(0);
                break;
            case KEY_s:
                world->save("save.txt");
                std::exit(0);
                break;
            default:
                for(Organism* organism : world->getOrganisms()) {
                    if(dynamic_cast<Human*>(organism)) {
                        dynamic_cast<Human*>(organism)->passKey(key);
                    }
                }
            }
        world->makeTurn();
        world->drawWorld();
        world->announce();

    }
    return 0;
}