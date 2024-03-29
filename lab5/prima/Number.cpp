#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

Number::Number(const char* value, int base)
{
	s = new char[100] {};
	strcpy(s, value);
	b = base;
	l = strlen(s);
}

Number::Number(long int x)
{
	s = new char[100] {};
	_ltoa(x, s, 10);
	b = 10;
	l = strlen(s);
}

Number::~Number()
{
	delete[] s;
	s = nullptr;
}

Number::Number(const Number& n)
{
	strcpy(s, n.s);
	l = n.l;
	b = n.b;
}

Number::Number(Number&& n)
{
	strcpy(s, n.s);
	l = n.l;
	b = n.b;
	n.s = nullptr;
	n.l = n.b = 0;
}

Number& Number::operator=(const Number& n)
{
	strcpy(s, n.s);
	b = n.b;
	l = n.l;
	return (*this);
}

Number& Number::operator=(const char* t)
{
	strcpy(s, t);
	b = 10;
	l = strlen(s);
	return (*this);
}

Number& Number::operator=(long int x)
{
	_ltoa(x, s, b);
	l = strlen(s);
	return (*this);
}

Number& Number::operator+=(const Number& n)
{
	*this = (*this) + n;
	return (*this);
}

Number& Number::operator-=(const Number& n)
{
	*this = (*this) - n;
	return (*this);
}

Number operator+(const Number& n1, const Number& n2)
{
	long int x = n1.GetBase10Value();
	long int y = n2.GetBase10Value();
	x = x + y;
	Number result(x);
	if (n1.b > n2.b)
		result.SwitchBase(n1.b);
	else
		result.SwitchBase(n2.b);
	return result;
}

Number operator-(const Number& n1, const Number& n2)
{
	long int x = n1.GetBase10Value();
	long int y = n2.GetBase10Value();
	x = x - y;
	Number result(x);
	if (n1.b > n2.b)
		result.SwitchBase(n1.b);
	else
		result.SwitchBase(n2.b);
	return result;
}

long int Number::GetBase10Value() const
{
	long int result = 0, power = 1;
	int i;
	for (i = l - 1; i >= 0; i--)
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result + (s[i] - '0') * power;
		else
			if(s[i]>='a'&&s[i]<='z')
				result = result + (s[i] - 'a' + 10) * power;
			else
				result = result + (s[i] - 'A' + 10) * power;
		power = power * b;
	}
	return result;
}

char Number::operator[](int k)
{
	if(k>=0&&k<l)
		return s[k];
	return -1;
}

bool Number::operator>(const Number& n)
{
	if (b == n.b)
		if (strcmp(s, n.s) > 0)
			return true;
		else
			return false;
	long int n1 = GetBase10Value();
	long int n2 = n.GetBase10Value();
	return n1 > n2;
}

bool Number::operator<(const Number& n)
{
	if (b == n.b)
		if (strcmp(s, n.s) < 0)
			return true;
		else
			return false;
	long int n1 = GetBase10Value();
	long int n2=n.GetBase10Value();
	return n1 < n2;
}

bool Number::operator>=(const Number& n)
{
	if (b == n.b)
		if (strcmp(s, n.s) >= 0)
			return true;
		else
			return false;
	long int n1 = GetBase10Value();
	long int n2 = n.GetBase10Value();
	return n1 >= n2;
}

bool Number::operator<=(const Number& n)
{
	if (b == n.b)
		if (strcmp(s, n.s) <= 0)
			return true;
		else
			return false;
	long int n1 = GetBase10Value();
	long int n2 = n.GetBase10Value();
	return n1 <= n2;
}

bool Number::operator==(const Number& n)
{
	if (b == n.b)
		if (strcmp(s, n.s) == 0)
			return true;
		else
			return false;
	long int n1 = GetBase10Value();
	long int n2 = n.GetBase10Value();
	return n1 == n2;
}

bool Number::operator!=(const Number& n)
{
	if (b == n.b)
		if (strcmp(s, n.s) != 0)
			return true;
		else
			return false;
	long int n1 = GetBase10Value();
	long int n2 = n.GetBase10Value();
	return n1 != n2;
}

Number& Number::operator--(int x)
{
	s[--l] = NULL;
	return (*this);
}

Number& Number::operator--()
{
	strcpy(s, s + 1);
	l--;
	return (*this);
}

void Number::SwitchBase(int newBase)
{
	if (newBase != b)
	{
		long int x = GetBase10Value();
		_ltoa(x, s, newBase);
		b = newBase;
		l = strlen(s);
	}
}

void Number::Print()
{
	printf("%s\n", s);
}

int Number::GetDigitsCount()
{
	return l;
}

int Number::GetBase()
{
	return b;
}