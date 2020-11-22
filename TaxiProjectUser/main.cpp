#include <iostream>
#include <fstream>
#include <ostream>
#include "Driver.h"
#include "Taxi.h"
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
		cout << "3. Rent a taxi" << endl;
		cout << "4. Exit" << endl;
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

		else if (user == '3') {
			com.RentTaxi();

		}
		else {
			break;
		}



	}

}

int main() {

	showMenu();
	return 0;
}
