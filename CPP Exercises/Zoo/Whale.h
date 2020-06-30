#ifndef WHALE_H
#define WHALE_H
#include "fish.h"
#include "Imammal.h"

class Whale: public Fish, public Imammal
{
public:
	Whale(std::string name) :Fish(name){}
	/*virtual*/ const std::vector<std::string>& getSpecies()const;
	/*virtual*/ unsigned int getLifeExpectancy()const;
	/*virtual*/ const std::vector<E_CONTINENTS>& getContinents()const;
	/*virtual*/ const std::vector<std::string>& getFood()const;
	/*virtual*/ unsigned int getSpeed()const;
	/*virtual*/ unsigned int getDurationPregnancy()const;
	/*virtual*/ unsigned int getNumberYoungBorn()const;
	/*virtual*/ unsigned int getLowestDepth() const;
protected:
	std::ostream& printData(std::ostream& os)const;
private:
	static const std::vector<std::string> s_species;
	static const unsigned int s_lifeExpectancy = 12;
	static const std::vector<E_CONTINENTS> s_continents;
	static const std::vector<std::string> s_food;
	static const unsigned int s_speed = 100;
	static const unsigned int s_durationPregnancy = 3;
	static const unsigned int s_numberYoungBorn = 3;
	static const unsigned int s_lowestDepth = 500;

};
inline const std::vector<std::string>& Whale::getSpecies()const
{
	return s_species;
}
inline unsigned int Whale::getLifeExpectancy()const
{
	return s_lifeExpectancy;
}
inline const std::vector<E_CONTINENTS>& Whale::getContinents()const
{
	return s_continents;
}
inline const std::vector<std::string>& Whale::getFood()const
{
	return s_food;
}
inline unsigned int Whale::getSpeed()const
{
	return s_speed;
}
inline unsigned int Whale::getDurationPregnancy()const
{
	return s_durationPregnancy;
}
inline unsigned int Whale::getNumberYoungBorn()const
{
	return s_numberYoungBorn;
}
inline unsigned int Whale::getLowestDepth() const
{
	return s_lowestDepth;
}
#endif
