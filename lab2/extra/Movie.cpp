#define _CRT_SECURE_NO_WARNINGS
#include"Movie.h"
#include <iostream>
#include<cstring>

void Movie::set_name(const char s[])
{
	strcpy(name, s);
}

char* Movie::get_name()
{
	char* s = name;
	return s;
}

void Movie::set_year(unsigned int x)
{
	year = x;
}

unsigned int Movie::get_year()
{
	return year;
}

void Movie::set_score(double x)
{
	score = x;
}

double Movie::get_score()
{
	return score;
}

void Movie::set_length(unsigned int x)
{
	length = x;
}

unsigned int Movie::get_length()
{
	return length;
}

unsigned int Movie::get_passed_years()
{
	return 2024 - year;
}

void movieseries::init()
{
	count = 0;
}

void movieseries::add(Movie *a)
{
	v[count] = a;
	count++;
}

void movieseries::print()
{
	unsigned int i;
	for (i = 0; i < count; i++)
		std::cout << v[i]->get_name() << ' ' << v[i]->get_year() << ' ' << v[i]->get_score() << ' ' << v[i]->get_length() << ' ' << v[i]->get_passed_years() << '\n';
}

void movieseries::sort()
{
	unsigned int i, j;
	Movie* a;
	for(i=0;i<count-1;i++)
		for(j=i+1;j<count;j++)
			if (v[i]->get_passed_years() < v[j]->get_passed_years())
			{
				a = v[i];
				v[i] = v[j];
				v[j] = a;
			}
}