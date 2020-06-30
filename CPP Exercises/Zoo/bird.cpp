#include "bird.h"
std::ostream& Bird::printData(std::ostream& os)const
{
    Animal::printData(os);
    os << "typical height:" << getTypicalHeight() << std::endl;
    os << "wing-span:" << getWingSpan() << std::endl;
    return os;
}