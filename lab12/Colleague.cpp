#include "Colleague.h"

Colleague::Colleague(string nume) {
	name = nume;
	type = colleague_type;
	phone_number = "0734890765";
	company = "Dedeman";
	address = "Iasi";
}

string Colleague::GetName() 
{
	return name;
}

ContactType Colleague::GetType() 
{
	return type;
}