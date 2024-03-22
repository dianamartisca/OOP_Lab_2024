#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstdlib>
#include <iostream>
#include <cstdarg>
#include <cstring>

Sort::Sort(int nr, int min, int max)
{
	srand(time(NULL));
	n = nr;
	v = new int[nr];
	for (int i = 0; i < nr; i++)
		v[i] = rand() % (max - min + 1) + min;
}

Sort::Sort():v(new int[10]{1,2,3,4,5,6,7,8,9,10})
{
	n = 10;
}

Sort::Sort(int a[], int nr)
{
	n = nr;
	v = new int[n];
	for (int i = 0; i < n; i++)
		v[i] = a[i];
}

Sort::Sort(int nr, ...)
{
	va_list args;
	va_start(args, nr);
	v = new int[nr];
	n = nr;
	for (int i = 0; i < n; i++)
		v[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(char s[])
{
	int nr = strlen(s),x;
	n = 0;
	v = new int[nr];
	char* p;
	p = strtok(s, ",");
	while (p)
	{
		int x = atoi(p);
		v[n++] = x;
		p = strtok(NULL, ",");
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1, x=v[i];
		while (j >= 0)
		{
			if (v[j] < x && ascendent || v[j] > x && !ascendent)
				break;
			v[j + 1] = v[j];
			j = j - 1; 
		}
		v[j + 1] = x;
	}
}

void Sort::QuickSort(int l,int r,bool ascendent)
{
	if (l < r)
	{
		int p = v[r];
		int i = l - 1;
		int aux;
		for(int j=l;j<=r;j++)
			if (v[j]<p && ascendent || v[j]>p && !ascendent)
			{
				i++;
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}
		aux = v[i + 1];
		v[i + 1] = v[r];
		v[r] = aux;
		int pivot = i + 1;
		QuickSort(l, pivot - 1, ascendent);
		QuickSort(pivot + 1, r, ascendent);
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int ok, i, aux;
	do
	{
		ok = 1;
		for(i=0;i<n-1;i++)
			if (ascendent && v[i] > v[i + 1] || !ascendent && v[i] < v[i + 1])
			{
				ok = 0;
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
			}
	} while (!ok);
}

void Sort::Print()
{
	int i;
	for (i = 0; i < n; i++)
		std::cout << v[i] << ' ';
	std::cout << '\n';
}

int  Sort::GetElementsCount()
{
	return n;
}

int  Sort::GetElementFromIndex(int index)
{
	return v[index];
}