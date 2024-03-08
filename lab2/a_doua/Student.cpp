#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
#include<cstring>

void Student::SetNume(const char s[])
{
	strcpy(nume, s);
}

char* Student::GetNume()
{
	char* s = nume;
	return s;
}

void Student::SetMate(float x)
{
	if (x >= 1 && x <= 10)
		mate = x;
}

float Student::GetMate()
{
	return mate;
}

void Student::SetEng(float x)
{
	if (x >= 1 && x <= 10)
		eng = x;
}

float Student::GetEng()
{
	return eng;
}

void Student::SetIst(float x)
{
	if (x >= 1 && x <= 10)
		ist = x;
}

float Student::GetIst()
{
	return ist;
}

float Student::GetAvg()
{
	return (mate + eng + ist) / 3;
}