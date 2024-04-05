#pragma once
#include "Car.h"
#include "Weather.h"

class Fiat :public Car
{
public:
	Fiat();
	unsigned int racetime(unsigned int circuitlength, Weather condition);
	unsigned int maxlength();
	char* GetName();
};
