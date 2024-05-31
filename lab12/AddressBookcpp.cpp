#include "AddressBook.h"
#include<iostream>

using namespace std;

bool AddressBook::FindContact(string contact_name) {
	unsigned int i;
	for (i = 0; i < nr_contacts; i++)
		if (contacts[i]->GetName() == contact_name)
			return true;
	return false;
}

Contact** AddressBook::FindFriends() {
	Contact* friends[100];
	unsigned int i, k = 0;
	for (i = 0; i < nr_contacts; i++)
		if (contacts[i]->GetType() == friend_type)
			friends[k++] = contacts[i];
	friends[k] = nullptr;
	return friends;
}

void AddressBook::DeleteContact(string contact_name) {
	unsigned int i;
	int p = -1;
	for (i = 0; i < nr_contacts; i++)
		if (contacts[i]->GetName() == contact_name)
		{
			p = i;
			break;
		}
	if (p >= 0)
	{
		for (i = p; i < nr_contacts - 1; i++)
			contacts[i] = contacts[i + 1];
		nr_contacts--;
	}
}

void AddressBook::AddContact(Contact* cont) {
	contacts[nr_contacts] = cont;
	nr_contacts++;
}

AddressBook::AddressBook() {
	nr_contacts = 0;
}

void AddressBook::Print()
{
	unsigned int i;
	for (i = 0; i < nr_contacts; i++)
		cout << contacts[i]->GetName() << ' ';
	cout << '\n';
}