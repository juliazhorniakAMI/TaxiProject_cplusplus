#ifndef Car_H
#define Car_H
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Car : public Vehicle{
	


public:

 void Write();
	Car(string make="", int number=0, string color="", float MaxSpeed=0);
	
	
	string GetStorageName() {
		return "C:\\oop\\Taxi_rep-master\\data\\Taxi.txt";
	}

	friend ifstream& operator>>(ifstream& fin, Car& taxi);
	friend ofstream& operator<<(ofstream& fout, Car& taxi);

};
#endif

