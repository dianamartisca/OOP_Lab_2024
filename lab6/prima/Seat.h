#pragma once
#include "Car.h"
#include "Weather.h"

class Seat :public Car
{
public:
	Seat();
	unsigned int racetime(unsigned int circuitlength, Weather condition);
	unsigned int maxlength();
	char* GetName();
};
