#include "Driver.h"
#include "Taxi.h"
//#include "Command.h"
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Driver::Driver(string name, int rate, int price) :Person(name)

{


	this->rate = rate;
	this->price = price;


}

void Driver::Write() {

	cout << "            Info of the driver: " << endl;

	cout << "name: " << name << " \nResidence: " << residence << " \nRate: " << rate << endl;
	cout << "Price: " << price << endl;




}
ifstream& operator>>(ifstream& fin, Driver& driver) {

	string name;
	int rate;
	int price;



	fin >> name >> rate >> price;
	
		driver.name = name;
		driver.rate = rate;
		driver.price = price;
	

	return fin;
}


ofstream& operator<<(ofstream& fout, Driver& driver) {
	fout << driver.GetInfo();//адреси зберігає
	return fout;
}