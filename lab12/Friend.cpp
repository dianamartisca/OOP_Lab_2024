#include "Friend.h"

Friend::Friend(string nume) {
	name = nume;
	type = friend_type;
	date_of_birth = "1.04.2004";
	phone_number = "0734890765";
	address = "Iasi";
}

string Friend::GetName() 
{
	return name;
}

ContactType Friend::GetType() 
{
	return type;
}