#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include"Contact.h"
#include<string>

using namespace std;

class AddressBook {

private:
	Contact* contacts[100];
	unsigned int nr_contacts;

public:
	bool FindContact(string contact_name);

	Contact** FindFriends();

	void DeleteContact(string contact_name);

	void AddContact(Contact* cont);

	AddressBook();

	void Print();
};

#endif
