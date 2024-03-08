#pragma once

class Student
{
	char nume[30];
	float mate, eng, ist;

public:
	void SetNume(const char s[]);
	char* GetNume();
	void SetMate(float nota);
	float GetMate();
	void SetEng(float nota);
	float GetEng();
	void SetIst(float nota);
	float GetIst();
	float GetAvg();
};
