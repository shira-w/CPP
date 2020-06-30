#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

enum E_CONTINENTS
{
    E_AMERICA,
    E_ASIA,
    E_AUSTRALIA,
    E_ANTARTICA,
    E_AFRICA,
    E_EUROPE
};

class Animal
{
public:
    Animal(const std::string& name);
    virtual ~Animal();
    virtual const std::vector <std::string>& getSpecies()const = 0;
    virtual unsigned int getLifeExpectancy()const = 0;
    virtual const std::vector<E_CONTINENTS>& getContinents()const = 0;
    virtual const std::vector<std::string>& getFood()const = 0;
    virtual unsigned int getSpeed()const = 0;

protected:
    virtual std::ostream& printData(std::ostream& os) const;

private:
    std::string m_name;

friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
friend std::ostream& operator<<(std::ostream& os, const Animal* animal);
};

inline Animal::Animal(std::string name):m_name(name){}

inline  Animal::~Animal(){
}


#endif 
