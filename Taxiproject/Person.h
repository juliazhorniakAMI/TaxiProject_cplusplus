#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;
class Person
{
protected:
	string residence;

public:
	virtual void Write() {}
	string name;
	Person(string name) {
		this->residence = "LVIV";
		this->name = name;
	};

};
#endif


