#ifndef DRIVER_H
#define DRIVER_H
#include "Person.h"
#include "Client.h"
#include "Taxi.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Driver :public Person {


	int price;
public:

	int rate;
	Driver(string name = "", int rate = 0, int price = 0);
	string GetInfo() {

		return name + " " + to_string(rate) + " " + to_string(price);
	}
	void Write();
	string GetStorageName() {
		return "C:\\oop\\Taxi_rep-master\\data\\Driver.txt";
	}

	friend ifstream& operator>>(ifstream& fin, Driver& taxi);
	friend ofstream& operator<<(ofstream& fout, Driver& taxi);
};
#endif

