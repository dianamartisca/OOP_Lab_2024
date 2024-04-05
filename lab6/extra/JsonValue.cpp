#define _CRT_SECURE_NO_WARNINGS
#include"JsonValue.h"
#include<iostream>
#include<cstring>

NullValue::NullValue()
{
	null = NULL;
}

NullValue::~NullValue()
{
	null = NULL;
}

void NullValue::print(std::ostream& out)
{
	out << "NULL";
}

NumberValue::NumberValue(int x)
{
	nr = x;
}

NumberValue::~NumberValue()
{
	nr = NULL;
}

void NumberValue::print(std::ostream& out)
{
	out << nr;
}

BoolValue::BoolValue(bool a)
{
	b = a;
}

BoolValue::~BoolValue()
{
	b = NULL;
}

void BoolValue::print(std::ostream& out)
{
	out << b;
}

StringValue::StringValue(const char* str)
{
	s = new char[255];
	strcpy(s, str);
}

StringValue::~StringValue() 
{
	delete [] s;
	s = nullptr;
}

void StringValue::print(std::ostream& out)
{
	out << s;
}

ArrayValue::ArrayValue()
{
	v = new JsonValue*[16];
	elem = 0;
}

ArrayValue::~ArrayValue()
{
	unsigned int i;
	for (i = 0; i < elem; i++)
	{
		delete v[i];
		v[i] = nullptr;
	}
	delete [] v;
	v = nullptr;
	elem = NULL;
}

void ArrayValue::print(std::ostream& out)
{
	if (elem > 0)
	{
		unsigned int i;
		out << "[ ";
		for (i = 0; i < elem; i++)
		{
			v[i]->print(std::cout);
			out << ' ';
		}
		out << ']';
	}
}

void ArrayValue::add(JsonValue* x)
{
	v[elem++] = x;
}

ArrayValue::operator unsigned()
{
	return (unsigned)elem;
}

ObjectValue::ObjectValue()
{
	pair_array = new std::pair<char*, JsonValue*>[16];
	objs = 0;
}

ObjectValue::~ObjectValue()
{
	unsigned int i = 0;
	for (i = 0; i < objs; i++)
	{
		delete [] pair_array[i].first;
		pair_array[i].first = nullptr;
		delete pair_array[i].second;
		pair_array[i].second = nullptr;
	}
	delete[] pair_array;
	pair_array = nullptr;
	objs = NULL;
}

void ObjectValue::print(std::ostream& out)
{
	if (objs > 0)
	{
		out << '{';
		unsigned int i;
		for (i = 0; i < objs; i++)
		{
			out << '"' << pair_array[i].first << '"' << ": ";
			pair_array[i].second->print(std::cout);
			out << ' ';
		}
		out << '}';
	}
}

void ObjectValue::add(const char* str, JsonValue* x)
{
	pair_array[objs].first = new char[255];
	strcpy(pair_array[objs].first, str);
	pair_array[objs].second = x;
	objs++;
}

ObjectValue::operator unsigned()
{
	unsigned int k = 0,i;
	for (i = 1; i < objs; i++)
		k += (unsigned)pair_array[i].second;
	return (unsigned) k;
}