#ifndef FISH_H
#define FISH_H

#include "animal.h"
#include "Ifish.h"

class Fish :public Animal,public Ifish
{
public:
    Fish(std::string name) :Animal(name) {}
protected:
    /*virtual*/ std::ostream& printData(std::ostream& os)const;
};

#endif
