#include<iostream>

template <class T>
class Vector
{
	T* v;
	unsigned int count;
public:
	Vector()
	{
		v = new T[100];
		count = 0;
	}

	Vector(const Vector& c)
	{
		v = new T[100];
		unsigned int i;
		for (i = 0; i < c.count; i++)
			v[i] = c.v[i];
		count = c.count;
	}

	Vector(Vector&& m)
	{
		v = new T[100];
		unsigned int i;
		for (i = 0; i < m.count; i++)
			v[i] = m.v[i];
		count = m.count;
		delete[] m.v;
		m.v = nullptr;
		m.count = NULL;
	}

	T operator[](int index)
	{
		return v[index];
	}

	void insert(int index, T elem)
	{
		if (index >= 0 && index <= count)
		{
			unsigned int j;
			for (j = count; j > index; j--)
				v[j] = v[j - 1];
			count++;
			v[index] = elem;
		}
	}

	void remove(int index)
	{
		if (index >= 0 && index < count)
		{
			unsigned int j;
			for (j = index; j < count - 1; j++)
				v[j] = v[j + 1];
			count--;
		}
	}

	void sort(int (*cmp)(T x, T y))
	{
		unsigned int i, j;
		for(i=0;i<count-1;i++)
			for(j=i+1;j<count;j++)
				if (cmp(v[i], v[j]) > 0)
				{
					T aux;
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
	}

	void sort()
	{
		unsigned int i, j;
		for (i = 0; i < count - 1; i++)
			for (j = i + 1; j < count; j++)
				if (v[i]< v[j])
				{
					T aux;
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
	}

	void print()
	{
		unsigned int i;
		for (i = 0; i < count; i++)
			std::cout << v[i] << ' ';
		std::cout << '\n';
	}
};
