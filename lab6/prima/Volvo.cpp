#include "Volvo.h"
#include "Weather.h"
#include <cstring>

Volvo::Volvo()
{
	fuelcapacity = 55;
	fuelconsumption = 12;
	avgspeed[Weather::Rain] = 100;
	avgspeed[Weather::Sunny] = 120;
	avgspeed[Weather::Snow] = 90;
	name = new char[50];
	strcpy(name, "Volvo");
}

unsigned int Volvo::racetime(unsigned int circuitlength, Weather condition)
{
	return circuitlength / avgspeed[condition];
}

unsigned int Volvo::maxlength()
{
	return fuelcapacity / fuelconsumption * 100;
}

char* Volvo::GetName()
{
	return name;
}