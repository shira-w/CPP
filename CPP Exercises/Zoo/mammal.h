#ifndef MAMMAL_H
#define MAMMAL_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "Imammal.h"

class Mammal : public Imammal, public Animal
{
public:
    Mammal(const std::string& name) :Animal(name){}
protected:
    /*virtual*/ std::ostream& printData(std::ostream& os)const;
};
#endif

