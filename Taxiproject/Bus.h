#ifndef BUS_H
#define BUS_H
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Bus : public Vehicle {



public:

	void Write();
	Bus(string make = "", int number = 0, string color = "", float MaxSpeed = 0);


	string GetStorageName() {
		return "C:\\oop\\Taxi_rep-master\\data\\Bus.txt";
	}

	friend ifstream& operator>>(ifstream& fin, Bus& taxi);
	friend ofstream& operator<<(ofstream& fout, Bus& taxi);

};
#endif


