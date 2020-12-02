#include "DriverBus.h"
#include "Car.h"
//#include "Command.h"
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

DriverBus::DriverBus(string name, int rate, int price) :Person(name)

{


	this->rate = rate;
	this->price = price;


}

void DriverBus::Write() {

	//cout << "            Info of the driver: " << endl;

	cout << "name: " << name << " \nResidence: " << residence << " \nRate: " << rate << endl;
	cout << "Price: " << price << endl;




}
ifstream& operator>>(ifstream& fin, DriverBus& driver) {

	string name;
	int rate;
	int price;




	fin >> name >> rate >> price;
	
		driver.name = name;
		driver.rate = rate;
		driver.price = price;


	return fin;
}


ofstream& operator<<(ofstream& fout, DriverBus& driver) {
	fout << driver.GetInfo();//адреси зберігає
	return fout;
}