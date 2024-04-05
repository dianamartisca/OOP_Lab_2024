#pragma once
#include "Car.h"
#include "Weather.h"

class Volvo:public Car
{
	public:
		Volvo();
		unsigned int racetime(unsigned int circuitlength, Weather condition);
		unsigned int maxlength();
		char* GetName();
};
