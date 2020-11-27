#ifndef TAXI_H
#define TAXI_H
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Taxi : public Vehicle{
	


public:

 void Write();
	Taxi(string make="", int number=0, string color="", float MaxSpeed=0);
	
	
	string GetStorageName() {
		return "C:\\oop\\Taxi_rep-master\\data\\Taxi.txt";
	}

	friend ifstream& operator>>(ifstream& fin, Taxi& taxi);
	friend ofstream& operator<<(ofstream& fout, Taxi& taxi);

};
#endif

