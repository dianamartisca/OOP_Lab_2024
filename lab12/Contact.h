#ifndef CONTACT_H
#define CONTACT_H
#include"ContactType.h"
#include<string>
using namespace std;

class Contact {
protected:
	string name;
	ContactType type;
public:
	virtual string GetName() = 0;
	virtual ContactType GetType() = 0;
};

#endif
