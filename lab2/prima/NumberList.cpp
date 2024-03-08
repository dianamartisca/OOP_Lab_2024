#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count] = x;
	count++;
	return true;
}

void NumberList::Sort()
{
	int i, j,aux;
	for(i=0;i<count-1;i++)
		for(j=i+1;j<count;j++)
			if (numbers[i] > numbers[j])
			{
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
}

void NumberList::Print()
{
	int i;
	for (i = 0; i < count; i++)
		std::cout << numbers[i] << ' ';
	std::cout << '\n';
}

