#include "Taxi.h"

//#include "Command.h"
#include <iostream>
using namespace std;
Taxi::Taxi(string make, int number, string color, float MaxSpeed) :Vehicle(make, number, color, MaxSpeed) {




};


void Taxi:: Write() {

	cout << "_____Taxi information____: " << endl;

	cout<<"Make: "<<make << " \nNumber: " << number << " \nColor: " << color << " \nMaxSpeed: " << MaxSpeed << endl<<endl;
}

ifstream& operator>>(ifstream& fin, Taxi& taxi) {
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


ofstream& operator<<(ofstream& fout, Taxi& taxi) {
	fout << taxi.GetInfo();//адреси зберігає
	return fout;
}
