#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "Ibird.h"

class Bird : public Animal,public Ibird
{
public:
    Bird(std::string name) :Animal(name) {}
protected:
    /*virtual*/std::ostream& printData(std::ostream& os)const;
};



#endif
