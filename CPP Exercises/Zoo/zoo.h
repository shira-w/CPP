#ifndef ZOO_H
#define ZOO_H

#include "lion.h"
#include "owl.h"
#include "shark.h"
#include "Whale.h"

class Zoo
{
public:
	Zoo(const std::vector <Animal*>& animals);
private:
	std::vector <Animal*> m_animals;

friend std::ostream& operator<<(std::ostream& os, const Zoo& zoo);
friend std::ostream& operator<<(std::ostream& os, const Zoo* zoo);
};

inline Zoo::Zoo(const std::vector <Animal*>& animals)
{
	m_animals=animals;
}

#endif
