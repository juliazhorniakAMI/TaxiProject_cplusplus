#ifndef COMMAND_H
#define COMMAND_H
#include "Taxi.h"
#include "Driver.h"
#include "Person.h"

#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <string>


#include "Repository.h"
#include <iostream>
using namespace std;

class Command {

public:

	Repository<Taxi> taxiRepository = Repository<Taxi>(true);


	Repository<Driver> driverRepository = Repository<Driver>(true);

	void Print();




	void WriteAllDrivers();
	void AddTaxi(Taxi& taxi);
	void AddDriver(Driver&);


	void showRate();
	void changeRate();


};
#endif




