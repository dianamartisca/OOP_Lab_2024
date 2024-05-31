#ifndef FRIEND_H
#define FRIEND_H
#include"Contact.h"
#include<string>
using namespace std;

class Friend : public Contact {

private:
	string date_of_birth;
	string phone_number;
	string address;
public:
	Friend(string nume);
	string GetName();
	ContactType GetType();
};

#endif
