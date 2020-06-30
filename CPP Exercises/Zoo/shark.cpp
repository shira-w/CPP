#include "shark.h"

std::string tempS[] = {"dalfon","afarendo"};
const std::vector<std::string>  Shark::s_species(tempS, tempS+ sizeof(tempS) / sizeof(tempS[0]));
E_CONTINENTS temp2S[] = { E_ANTARTICA, E_EUROPE };
const std::vector<E_CONTINENTS> Shark::s_continents(temp2S, temp2S + sizeof(temp2S) / sizeof(temp2S[0]));
std::string temp3S[] = { "dgigim","dgigonim" };
const std::vector<std::string> Shark::s_food(temp3S, temp3S + sizeof(temp3S) / sizeof(temp3S[0]));

std::ostream& Shark::printData(std::ostream& os)const
{
    os << "I am shark:" << std::endl;
    Fish::printData(os);
    os << "----------------------" << std::endl;
    return os;
}
