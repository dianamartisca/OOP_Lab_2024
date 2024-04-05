#include "RangeRover.h"
#include "Weather.h"
#include<cstring>

RangeRover::RangeRover()
{
	fuelcapacity = 15;
	fuelconsumption = 20;
	avgspeed[Weather::Rain] = 130;
	avgspeed[Weather::Sunny] = 150;
	avgspeed[Weather::Snow] = 100;
	name = new char[50];
	strcpy(name, "RangeRover");
}

unsigned int RangeRover::racetime(unsigned int circuitlength, Weather condition)
{
	return circuitlength / avgspeed[condition];
}

unsigned int RangeRover::maxlength()
{
	return fuelcapacity / fuelconsumption * 100;
}

char* RangeRover::GetName()
{
	return name;
}