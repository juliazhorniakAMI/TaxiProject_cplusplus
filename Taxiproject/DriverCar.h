#ifndef DRIVERCAR_H
#define DRIVERCAR_H
#include "Person.h"
#include "Client.h"
#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class DriverCar :public Person {


	int price;
public:

	int rate;

	DriverCar(string name = "", int rate = 0, int price = 0);
	string GetInfo() {

		return name + " " + to_string(rate) + " " + to_string(price);
	}
	void Write();
	string GetStorageName() {
		return "C:\\oop\\Taxi_rep-master\\data\\Drivercar.txt";
	}

	friend ifstream& operator>>(ifstream& fin, DriverCar& taxi);
	friend ofstream& operator<<(ofstream& fout, DriverCar& taxi);
};
#endif


