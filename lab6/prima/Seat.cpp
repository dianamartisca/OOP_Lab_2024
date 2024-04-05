#include "Seat.h"
#include "Weather.h"
#include <cstring>

Seat::Seat()
{
	fuelcapacity = 60;
	fuelconsumption = 11;
	avgspeed[Weather::Rain] = 110;
	avgspeed[Weather::Sunny] = 130;
	avgspeed[Weather::Snow] = 95;
	name = new char[50];
	strcpy(name, "Seat");
}

unsigned int Seat::racetime(unsigned int circuitlength, Weather condition)
{
	return circuitlength / avgspeed[condition];
}

unsigned int Seat::maxlength()
{
	return fuelcapacity / fuelconsumption * 100;
}

char* Seat::GetName()
{
	return name;
}