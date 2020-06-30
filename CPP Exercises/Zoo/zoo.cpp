#include "zoo.h"

std::ostream& operator<<(std::ostream& os, const Zoo& zoo)
{
	std::vector<Animal*>::iterator ptr;
	std::vector<Animal*> a = zoo.m_animals;
	for (ptr = a.begin();ptr != a.end();ptr++)
		os << *ptr;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Zoo* zoo)
{
	std::vector<Animal*>::iterator ptr;
	std::vector<Animal*> a = zoo->m_animals;
	for (ptr = a.begin();ptr != a.end();ptr++)
		os << *ptr ;
	return os;
}
