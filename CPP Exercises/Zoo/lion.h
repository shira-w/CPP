#ifndef LION_H
#define LION_H

#include "mammal.h"

class Lion : public Mammal
{
public:
    Lion(std::string name) :Mammal(name) {}
    /*virtual*/ const std::vector<std::string>& getSpecies()const;
    /*virtual*/ unsigned int getLifeExpectancy()const;
    /*virtual*/ const std::vector<E_CONTINENTS>& getContinents()const;
    /*virtual*/ const std::vector<std::string>& getFood()const;
    /*virtual*/ unsigned int getSpeed()const;
    /*virtual*/ unsigned int getDurationPregnancy()const;
    /*virtual*/ unsigned int getNumberYoungBorn()const;

protected:
    /*virtual*/ std::ostream& printData(std::ostream& os)const;

private:
    static const std::vector<std::string> s_species;
    static const unsigned int s_lifeExpectancy = 12;
    static const std::vector<E_CONTINENTS> s_continents;
    static const std::vector<std::string> s_food;
    static const unsigned int s_speed = 100;
    static const unsigned int s_durationPregnancy = 3;
    static const unsigned int s_numberYoungBorn = 3;
};

inline const std::vector<std::string>& Lion::getSpecies()const
{
    return s_species;
}
inline unsigned int Lion::getLifeExpectancy()const
{
    return s_lifeExpectancy;
}
inline const std::vector<E_CONTINENTS>& Lion::getContinents()const
{
    return s_continents;
}
inline const std::vector<std::string>& Lion::getFood()const
{
    return s_food;
}
inline unsigned int Lion::getSpeed()const
{
    return s_speed;
}
inline unsigned int Lion::getDurationPregnancy()const
{
    return s_durationPregnancy;
}
inline unsigned int Lion::getNumberYoungBorn()const
{
    return s_numberYoungBorn;
}


#endif // !LION_H

