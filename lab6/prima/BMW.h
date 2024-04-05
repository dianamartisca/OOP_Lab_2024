#pragma once
#include "Car.h"
#include "Weather.h"

class BMW :public Car
{
public:
	BMW();
	unsigned int racetime(unsigned int circuitlength, Weather condition);
	unsigned int maxlength();
	char* GetName();
};
