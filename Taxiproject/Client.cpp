#include "Client.h"
#include "Person.h"
//#include "Command.h"
#include <string>
#include <iostream>
using namespace std;
Client::Client(string name, string address):Person(name) {


	this->address = address;


}

void Client::Write() {
	cout << "Information of client: " << endl;
	cout << "First name: " << name << " \nAddress: " << address << " " << endl;

}