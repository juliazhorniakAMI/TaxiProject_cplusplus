#include "Bus.h"

//#include "Command.h"
#include <iostream>
using namespace std;
Bus::Bus(string make, int number, string color, float MaxSpeed) :Vehicle(make, number, color, MaxSpeed) {




};


void Bus::Write() {

	//cout << "_____Bus information____: " << endl;

	cout << "Make: " << make << " \nNumber: " << number << " \nColor: " << color << " \nMaxSpeed: " << MaxSpeed <<endl<< endl;
}

ifstream& operator>>(ifstream& fin, Bus& Bus) {
	string make;
	int number;
	string color;
	float MaxSpeed;

	fin >> make >> number >> color >> MaxSpeed;
	Bus.make = make;
	Bus.number = number;
	Bus.color = color;
	Bus.MaxSpeed = MaxSpeed;

	return fin;

}


ofstream& operator<<(ofstream& fout, Bus& Bus) {
	fout << Bus.GetInfo();//адреси зберігає
	return fout;
}

