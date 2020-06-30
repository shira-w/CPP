#include "lion.h"
std::string temp[] = {"Barbaric","Asian"};
const std::vector<std::string> Lion::s_species(temp, temp + sizeof(temp) / sizeof(temp[0]));
E_CONTINENTS temp2[] = { E_ASIA,E_AFRICA };
const std::vector<E_CONTINENTS> Lion::s_continents(temp2, temp2 + sizeof(temp2) / sizeof(temp2[0]));
std::string temp3[] = { "tsavua","tan" };
const std::vector<std::string> Lion::s_food(temp3, temp3 + sizeof(temp3) / sizeof(temp3[0]));
std::ostream& Lion::printData(std::ostream& os)const
{
    os << "I am lion:" << std::endl;
    Mammal::printData(os);
    os << "----------------------" << std::endl;
    return os;
}