#include "fish.h"

std::ostream& Fish::printData(std::ostream& os)const
{
    Animal::printData(os);
    os << "lowest depth:" << getLowestDepth() << std::endl;
    return os;
}
