#pragma once
#include "Weather.h"

class Car
{
	protected:
		unsigned int fuelcapacity, fuelconsumption, avgspeed[3];
		char* name;
	public:
		virtual unsigned int racetime(unsigned int circuitlength, Weather condition) = 0;
		virtual unsigned int maxlength() = 0;
		virtual char* GetName() = 0;
};
