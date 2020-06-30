#ifndef SHARK_H_H
#define SHARK_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fish.h"

class Shark : public Fish
{
public:
    Shark(std::string name) :Fish(name) {}
    /*virtual*/ const std::vector<std::string>& getSpecies()const;
    /*virtual*/ unsigned int getLifeExpectancy()const;
    /*virtual*/ const std::vector<E_CONTINENTS>& getContinents()const;
    /*virtual*/ const std::vector<std::string>& getFood()const;
    /*virtual*/ unsigned int getSpeed()const;
    /*virtual*/ unsigned int getLowestDepth() const;

protected:
    /*virtual*/ std::ostream& printData(std::ostream& os)const;

private:
    static const std::vector<std::string> s_species;
    static const unsigned short int s_lifeExpectancy = 1;
    static const std::vector<E_CONTINENTS> s_continents;
    static const std::vector<std::string> s_food;
    static const unsigned int s_speed = 300;
    static const unsigned int s_lowestDepth = 500;
};

inline const std::vector<std::string>& Shark::getSpecies()const
{
    return s_species;
}
inline unsigned int Shark::getLifeExpectancy()const
{
    return s_lifeExpectancy;
}
inline const std::vector<E_CONTINENTS>& Shark::getContinents()const
{
    return s_continents;
}
inline const std::vector<std::string>& Shark::getFood()const
{
    return s_food;
}
inline unsigned int Shark::getSpeed()const
{
    return s_speed;
}
inline unsigned int Shark::getLowestDepth() const
{
    return s_lowestDepth;
}
#endif


