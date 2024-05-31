#include "Acquaintance.h"

Acquaintance::Acquaintance(string nume) {
	name = nume;
	type = acquaintance_type;
	phone_number = "0734890765";
}

string Acquaintance::GetName()
{
	return name;
}

ContactType Acquaintance::GetType()
{
	return type;
}
