#include "Fiat.h"
#include "Weather.h"
#include <cstring>

Fiat::Fiat()
{
	fuelcapacity = 50;
	fuelconsumption = 8;
	avgspeed[Weather::Rain] = 100;
	avgspeed[Weather::Sunny] = 140;
	avgspeed[Weather::Snow] = 80;
	name = new char[50];
	strcpy(name, "Fiat");
}

unsigned int Fiat::racetime(unsigned int circuitlength, Weather condition)
{
	return circuitlength / avgspeed[condition];
}

unsigned int Fiat::maxlength()
{
	return fuelcapacity / fuelconsumption * 100;
}

char* Fiat::GetName()
{
	return name;
}