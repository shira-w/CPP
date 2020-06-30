#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bird.h"

class Owl : public Bird
{
public:
    Owl(std::string name) :Bird(name){}
    /*virtual*/ const std::vector<std::string>& getSpecies()const;
    /*virtual*/ unsigned int getLifeExpectancy()const;
    /*virtual*/ const std::vector<E_CONTINENTS>& getContinents()const;
    /*virtual*/ const std::vector<std::string>& getFood()const;
    /*virtual*/ unsigned int getSpeed()const;
    /*virtual*/ unsigned int getTypicalHeight()const;
    /*virtual*/ unsigned int getWingSpan()const;

protected:
    /*virtual*/std::ostream& printData(std::ostream& os)const;

private:
    static const std::vector<std::string> s_species;
    static const unsigned int s_lifeExpectancy = 5;
    static const std::vector<E_CONTINENTS> s_continents;
    static const std::vector<std::string> s_food;
    static const unsigned int s_speed = 50;
    static const unsigned int s_typicalHeight = 1000;
    static const unsigned int s_wingSpan = 60;
};

inline const std::vector<std::string>& Owl::getSpecies()const
{
    return s_species;
}
inline unsigned int Owl::getLifeExpectancy()const
{
    return s_lifeExpectancy;
}
inline const std::vector<E_CONTINENTS>& Owl::getContinents()const
{
    return s_continents;
}
inline const std::vector<std::string>& Owl::getFood()const
{
    return s_food;
}
inline unsigned int Owl::getSpeed()const
{
    return s_speed;
}
inline unsigned int Owl::getTypicalHeight()const
{
    return s_typicalHeight;
}
inline unsigned int Owl::getWingSpan()const
{
    return s_wingSpan;
}



