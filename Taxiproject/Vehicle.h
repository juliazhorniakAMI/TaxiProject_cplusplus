#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;
class Vehicle 
{

protected:

	int number;
	string color;
	float MaxSpeed;
	string make;
public:
	virtual void Write() {}
	string GetMake() {

		return make;
	}
	string GetInfo() {

		return make + " "+ to_string(number) +" "+ color +" "+ to_string(MaxSpeed);
	}

	Vehicle(string make, int number, string color, float MaxSpeed) {

		this->make = make;

		this->number = number;
		this->color = color;
		this->MaxSpeed = MaxSpeed;

	}


	//
};
#endif

