#pragma once
#include "Car.h"
#include "Weather.h"

class RangeRover :public Car
{
public:
	RangeRover();
	unsigned int racetime(unsigned int circuitlength, Weather condition);
	unsigned int maxlength();
	char* GetName();
};
