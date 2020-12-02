#include "Car.h"

//#include "Command.h"
#include <iostream>
using namespace std;
Car::Car(string make, int number, string color, float MaxSpeed) :Vehicle(make, number, color, MaxSpeed) {




};


void Car:: Write() {

	//cout << "_____Taxi information____: " << endl;

	cout<<"Make: "<<make << " \nNumber: " << number << " \nColor: " << color << " \nMaxSpeed: " << MaxSpeed << endl<<endl;
}

ifstream& operator>>(ifstream& fin, Car& taxi) {
	string make;
	int number;
	string color;
	float MaxSpeed;

    fin >> make >> number >> color >> MaxSpeed;
	taxi.make = make;
	taxi.number = number;
	taxi.color = color;
	taxi.MaxSpeed = MaxSpeed;

	return fin;
		
}


ofstream& operator<<(ofstream& fout, Car& taxi) {
	fout << taxi.GetInfo();//адреси зберігає
	return fout;
}
