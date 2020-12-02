#ifndef DRIVERbus_H
#define DRIVERbus_H
#include "Person.h"
#include "Client.h"
#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class DriverBus :public Person {


	int price;
public:
	
	int rate;
	DriverBus(string name = "", int rate = 0, int price = 0);
	string GetInfo() {

		return name + " " + to_string(rate) + " " + to_string(price);
	}
	void Write();
	string GetStorageName() {
		return "C:\\oop\\Taxi_rep-master\\data\\Driverbus.txt";
	}

	friend ifstream& operator>>(ifstream& fin, DriverBus& taxi);
	friend ofstream& operator<<(ofstream& fout, DriverBus& taxi);
};
#endif

