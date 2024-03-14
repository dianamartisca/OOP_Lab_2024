#define _CRT_SECURE_NO_WARNINGS
#include"Math.h"
#include<cstdarg>
#include<cstring>
#include<cstdlib>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return int(x + y);
}

int Math::Add(double x, double y, double z)
{
	return int(x + y + z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return int(x * y);
}

int Math::Mul(double x, double y, double z)
{
	return int(x * y * z);
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list(args);
	va_start(args, count);
	for (int i = 1; i <= count; i++)
		sum += va_arg(args, int);
	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if (!s1 || !s2)
		return nullptr;
	char* s = (char*)malloc(sizeof(s1) + sizeof(s2));
	strcpy(s, s1);
	strcat(s, s2);
	return s;
}