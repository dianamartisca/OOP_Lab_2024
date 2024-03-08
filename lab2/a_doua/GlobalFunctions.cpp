#include"GlobalFunctions.h"
#include<cstring>

int compNume(Student& a, Student& b)
{
	if (strcmp(a.GetNume(), b.GetNume()) > 0)
		return 1;
	if (strcmp(a.GetNume(), b.GetNume()) < 0)
		return -1;
	return 0;
}

int compMate(Student& a, Student& b)
{
	if (a.GetMate() > b.GetMate())
		return 1;
	if (a.GetMate() < b.GetMate())
		return -1;
	return 0;
}

int compEng(Student& a, Student& b)
{
	if (a.GetEng() > b.GetEng())
		return 1;
	if (a.GetEng() < b.GetEng())
		return -1;
	return 0;
}

int compIst(Student& a, Student& b)
{
	if (a.GetIst() > b.GetIst())
		return 1;
	if (a.GetIst() < b.GetIst())
		return -1;
	return 0;
}

int compAvg(Student& a, Student& b)
{
	if (a.GetAvg() > b.GetAvg())
		return 1;
	if (a.GetAvg() < b.GetAvg())
		return -1;
	return 0;
}