#include "BMW.h"
#include "Weather.h"
#include <cstring>

BMW::BMW()
{
	fuelcapacity = 60;
	fuelconsumption = 13;
	avgspeed[Weather::Rain] = 130;
	avgspeed[Weather::Sunny] = 160;
	avgspeed[Weather::Snow] = 110;
	name = new char[50];
	strcpy(name, "BMW");
}

unsigned int BMW::racetime(unsigned int circuitlength, Weather condition)
{
	return circuitlength / avgspeed[condition];
}

unsigned int BMW::maxlength()
{
	return fuelcapacity / fuelconsumption * 100;
}

char* BMW::GetName()
{
	return name;
}