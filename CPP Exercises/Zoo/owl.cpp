#include "owl.h"

std::string tempO[] = {"Asio flammeus","Asio otus"};
const std::vector<std::string>  Owl::s_species(tempO, tempO + sizeof(tempO) / sizeof(tempO[0]));
E_CONTINENTS temp2O[] = {E_ANTARTICA,E_AFRICA};
const std::vector<E_CONTINENTS> Owl::s_continents(temp2O, temp2O + sizeof(temp2O) / sizeof(temp2O[0]));
std::string temp3O[] = {"betsim","korona"};
const std::vector<std::string> Owl::s_food(temp3O, temp3O + sizeof(temp3O) / sizeof(temp3O[0]));

 std::ostream& Owl::printData(std::ostream& os)const
{
    os << "I am snowy owl:" << std::endl;
    Bird::printData(os);
    os << "-------------------------"<<std::endl;
    return os;
}
