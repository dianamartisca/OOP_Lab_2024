#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
	private:
		unsigned int length;
		Weather condition;
		Car* cars[100];
		unsigned int nrCars=0;
		int* time;
	public:
		void SetLength(unsigned int length);
		void SetWeather(Weather condition);
		void AddCar(Car* car);
		void Race();
		void ShowFinalRanks();
		void ShowWhoDidNotFinish();
};
