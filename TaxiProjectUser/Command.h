#ifndef COMMAND_H
#define COMMAND_H
#include "Car.h"
#include "DriverCar.h"
#include "DriverBus.h"
#include "Person.h"
#include "Bus.h"
#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <string>


#include "Repository.h"
#include <iostream>
using namespace std;

class Command {

public:

	Repository<Car> taxiRepository = Repository<Car>(true);
	Repository<Bus> busRepository = Repository<Bus>(true);

	Repository<DriverCar> car_driverRepository = Repository<DriverCar>(true);
	Repository<DriverBus> bus_driverRepository = Repository<DriverBus>(true);



	void Print();




	void WriteAllDrivers();
	void AddTaxi(Car& taxi);
	void AddBus(Bus& bus);

	void Car_AddDriver(DriverCar& driver);
	void Bus_AddDriver(DriverBus& driver);

	void RentTaxi();
	void showRate();
	void changeRate();


};
#endif




