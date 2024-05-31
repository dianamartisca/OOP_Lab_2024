#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include"Contact.h"
#include<string>
using namespace std;

class Colleague : public Contact {

private:
	string phone_number;
	string company;
	string address;
public:
	Colleague(string nume);
	string GetName();
	ContactType GetType();
};

#endif
