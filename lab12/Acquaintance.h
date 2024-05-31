#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H
#include"Contact.h"
#include<string>
using namespace std;

class Acquaintance : public Contact {

private:
	string phone_number;
public:
	Acquaintance(string nume);
	string GetName();
	ContactType GetType();
};

#endif
