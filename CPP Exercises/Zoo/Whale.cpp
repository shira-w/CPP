#include "Whale.h"
std::string tempw[] = { "mush whale","blach-white whale" };
const std::vector<std::string> Whale::s_species(tempw, tempw + sizeof(tempw) / sizeof(tempw[0]));
E_CONTINENTS temp2w[] = { E_ASIA,E_AFRICA };
const std::vector<E_CONTINENTS> Whale::s_continents(temp2w, temp2w + sizeof(temp2w) / sizeof(temp2w[0]));
std::string temp3w[] = { "tsavua","tan" };
const std::vector<std::string> Whale::s_food(temp3w, temp3w + sizeof(temp3w) / sizeof(temp3w[0]));
std::ostream& Whale::printData(std::ostream& os)const
{
	os << "I am whale" << std::endl;
	Fish::printData(os);
	os << "duration pregnancy: " << getDurationPregnancy() << std::endl;
	os << "number of young born in litter: " << getNumberYoungBorn() << std::endl;
	return os;
}
