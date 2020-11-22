#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Client :public Person{
	
	string address;
public:
	Client(string name, string address);
	void Write();
};
#endif

