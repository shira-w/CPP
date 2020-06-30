#include "mammal.h"

std::ostream& Mammal::printData(std::ostream& os)const
{
    Animal::printData(os);
    os << "duration pregnancy: " << getDurationPregnancy() << std::endl;
    os << "number of young born in litter: " << getNumberYoungBorn() << std::endl;
    return os;
}
