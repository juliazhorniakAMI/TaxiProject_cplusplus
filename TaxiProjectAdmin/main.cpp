#include <iostream>
#include <fstream>
#include <ostream>
#include "DriverCar.h"
#include "DriverBus.h"
#include "Car.h"
#include "Client.h"

#include "Vehicle.h"
#include "Command.h"
#include "Repository.h"
#include <string>
using namespace std;

void showMenu() {
	//heelo
	Command com;


	while (true) {

		cout << "                        TAXI SERVICE: " << endl;
		cout << "   Choose an option: " << endl;
		cout << "1. Show available taxi " << endl;
		cout << "2. Show information of taxi drivers" << endl;
		//cout << "3. Rent a taxi" << endl;
		cout << "3. Exit" << endl;
		char user;
		try {

			cin >> user;
			if (!isdigit(user)) {
				throw "Not possible among options";
			}

		}
		catch (const char* a) {
			cout << "Error: " << a << endl;
		}

		if (user == '1') {
			com.Print();
			cout << endl;
			while (true) {
				cout << "1 Add taxi cars " << endl;
				cout << "2 Add taxi buses " << endl;
				cout << "3 Exit" << endl;
				cout << endl;

				char user2;

				cin >> user2;

				if (user2 == '1') {
					string make;
					int number;
					string color;
					float MaxSpeed;
					string name;
					int rate;
					int price;
					cout << "Enter Make,number,color and max speed:" << endl;
					cin >> make >> number >> color >> MaxSpeed;
					Car t(make, number, color, MaxSpeed);
					cout << "Enter Driver name,rate and price:" << endl;
					cin >> name >> rate >> price;
					DriverCar d(name, rate, price);
					com.AddTaxi(t);
					com.Car_AddDriver(d);

				}
				
				else if(user2=='2') {
					string make;
					int number;
					string color;
					float MaxSpeed;
					string name;
					int rate;
					int price;
					cout << "Enter Make,number,color and max speed:" << endl;
					cin >> make >> number >> color >> MaxSpeed;
					Bus t(make, number, color, MaxSpeed);
					cout << "Enter Driver name,rate and price:" << endl;
					cin >> name >> rate >> price;
					DriverBus d(name, rate, price);
					com.AddBus(t);
					com.Bus_AddDriver(d);

				}
				else {
					break;
				}
			}
		
		}
		else if (user == '2') {
			com.WriteAllDrivers();
			cout << endl;
			while (true) {
				cout << "A-- Show driver with max rating " << endl;
				cout << "B--Change rating in a certain driver" << endl;
				cout << "C-- Exit" << endl;
				cout << endl;

				char user2;

				cin >> user2;

				if (user2 == 'A') {
					com.showRate();
				}
				else if (user2 == 'B') {
					
					com.changeRate();
				}
				else {
					break;
				}
			}

		}

	/*	else if (user == '3') {
			com.RentTaxi();

		}*/
		else {
			break;
		}



	}

}

int main() {

	showMenu();
	return 0;
}