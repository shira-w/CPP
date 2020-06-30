#include "animal.h"

std::string tempCon[] = { "Amerika", "Asia", "Australia", "Antartica", "Africa", "Europe" };
const std::vector<std::string> continents(tempCon, tempCon + sizeof(tempCon) / sizeof(tempCon[0]));

std::ostream& Animal::printData(std::ostream& os)const
{
    os << "name: " << m_name << std::endl;
    os << "species: ";

    std::vector<std::string> s = getSpecies();
    std::vector<std::string>::iterator ptr;
    for (ptr = s.begin();ptr != s.end();ptr++)
        os << *ptr << " ";
    os << std::endl;

    os << "life expectancy: " << getLifeExpectancy() << std::endl;
    os << "continents: ";

    std::vector<E_CONTINENTS> c = getContinents();
    std::vector<E_CONTINENTS>::iterator ptr2;
    for (ptr2 = c.begin();ptr2 != c.end();ptr2++)
        os << continents[*ptr2] << " ";
    os << std::endl;

    os << "food: ";
    std::vector<std::string> f = getFood();
    std::vector<std::string>::iterator ptr3;
    for (ptr3 = f.begin();ptr3 != f.end();ptr3++)
        os << *ptr3 << " ";
    os << std::endl;
    os << "speed: " << getSpeed() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
    animal.printData(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Animal* animal)
{
    animal->printData(os);
    return os;
}
