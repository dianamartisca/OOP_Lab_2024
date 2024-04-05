#include "Circuit.h"
#include <iostream>

void Circuit::SetLength(unsigned int length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather condition)
{
	this->condition=condition;
}

void Circuit::AddCar(Car* car)
{
	cars[nrCars] = car;
	nrCars++;
}

void Circuit::Race()
{
	unsigned int i;
	time = new int[100];
	for (i = 0; i < nrCars; i++)
	{
		if (cars[i]->maxlength() < length)
			time[i] = -1;
		else
			time[i]= cars[i]->racetime(length, condition);
	}
}

void Circuit::ShowFinalRanks()
{
	unsigned int c[100], i, j;
	for (i = 0; i < nrCars; i++)
		c[i] = i;
	for (i = 0; i < nrCars - 1; i++)
		for (j = i + 1; j < nrCars; j++)
			if (time[c[i]] < time[c[j]])
				std::swap(c[i], c[j]);
	for (i = 0; i < nrCars; i++)
		if (time[c[i]] != -1)
			std::cout << cars[i]->GetName() << ' ' << time[c[i]] << "h\n";
}

void Circuit::ShowWhoDidNotFinish()
{
	unsigned int i;
	for (i = 0; i < nrCars; i++)
		if (time[i] == -1)
			std::cout << cars[i]->GetName() << " did not finish\n";
}

