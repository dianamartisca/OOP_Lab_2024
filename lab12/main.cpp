#include <iostream>
#include<string>
#include"AddressBook.h"
#include"Friend.h"
#include"Colleague.h"
#include"Acquaintance.h"
#include"Contact.h"
using namespace std;

int main()
{
    AddressBook a;
    a.AddContact(new Friend("Matei"));
    a.AddContact(new Colleague("Andrei"));
    a.AddContact(new Friend("Ioana"));
    if (a.FindContact("Ioana"))
        cout << "Ioana este unul dintre contacte.\n";
    else
        cout << "Ioana nu este unul dintre contacte.\n";
    Contact** friends_list = a.FindFriends();
    unsigned int i;
    for (i = 0; friends_list[i]; i++)
        cout << friends_list[i]->GetName() << ' ';
    a.DeleteContact("Matei");
    a.Print();
    return 0;
}
