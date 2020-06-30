#ifndef IBIRD_H
#define IBIRD_H
class Ibird
{
public:
	virtual unsigned int getTypicalHeight()const = 0;
	virtual unsigned int getWingSpan()const = 0;
};

#endif