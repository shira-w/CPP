#include "zoo.h"

int main()
{
    Lion mylion("Simba");
    Shark myshark("Jaws");
    Owl snowyOwl("Hedwig");
    Whale wo("goni");
    Animal* inner[]= { &mylion, &myshark, &snowyOwl,&wo };
    const std::vector<Animal*>animals(inner, inner + sizeof(inner) / sizeof(inner[0]));
    Zoo zoo1(animals);
    std::cout << &zoo1;
    return 1;
}