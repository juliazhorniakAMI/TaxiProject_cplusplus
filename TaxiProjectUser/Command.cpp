
#include "Command.h"
#include "Command.h"
#include "Car.h"
#include "Taxi.h"
#include "Driver.h"
#include "Client.h"
#include "Repository.h"
#include <iostream>
#include <algorithm>
#include <fstream>

#include <string>



void Command::AddTaxi(Car& taxi)
{
    taxiRepository.Add(taxi);
}

void Command::Car_AddDriver(DriverCar& driver)
{
    car_driverRepository.Add(driver);
}
void Command::Bus_AddDriver(DriverBus& driver)
{
    bus_driverRepository.Add(driver);
}
void Command::AddBus(Bus& bus)
{
    busRepository.Add(bus);
}

void Command::Print() {


    Taxi* _car = new carTaxi(*(new SimpleTaxi<Car>(taxiRepository.GetEntity())));
    _car->Info();
    Taxi* _bus = new busTaxi(*(new SimpleTaxi<Bus>(busRepository.GetEntity())));
    _bus->Info();

    delete _car;
    delete _bus;

}

void Command::WriteAllDrivers() {




    for (int i = 0; i < car_driverRepository.GetEntity().size(); i++) {
        Driver* _cdriver = new driver_car_decorator(*(new SimpleDriver<DriverCar>(car_driverRepository.GetEntity()[i])));
        Taxi* _car = new carTaxi(*(new SimpleTaxi<Car>(taxiRepository.GetEntity()[i])));
        _cdriver->Info_Elem();
        _car->Info_Elem();


        cout << endl;
        delete _cdriver;
        delete _car;
    }

    for (int i = 0; i < bus_driverRepository.GetEntity().size(); i++) {
        Driver* _bdriver = new driver_bus_decorator(*(new SimpleDriver<DriverBus>(bus_driverRepository.GetEntity()[i])));
        Taxi* _bus = new busTaxi(*(new SimpleTaxi<Bus>(busRepository.GetEntity()[i])));
        _bdriver->Info_Elem();
        _bus->Info_Elem();


        cout << endl;
        delete _bdriver;
        delete _bus;
    }

}

void Command::RentTaxi() {
    string nameoftaxi;
    int k;
    cout << "Enter the number of seats from 1-8 you need for a taxi: " << endl;
    cin >> k;
  
    if (k <= 4) {
        for (int i = 0; i < taxiRepository.GetEntity().size(); i++) {

            taxiRepository.GetEntity()[i].Write();


        }
        cout << "Write the name of a taxi car you want to rent: " << endl;
        cin >> nameoftaxi;
       
        for (int i = 0; i < taxiRepository.GetEntity().size(); i++) {

            if (nameoftaxi == taxiRepository.GetEntity()[i].GetMake()) {

                taxiRepository.deleteByIndex(i);
                car_driverRepository.deleteByIndex(i);
            }


        }
    }
    else if (5 <= k <= 8) {
        for (int i = 0; i <busRepository.GetEntity().size(); i++) {

            busRepository.GetEntity()[i].Write();


        }
        cout << "Write the name of a taxi bus you want to rent: " << endl;
        cin >> nameoftaxi;
        for (int i = 0; i < busRepository.GetEntity().size(); i++) {

            if (nameoftaxi == busRepository.GetEntity()[i].GetMake()) {

                busRepository.deleteByIndex(i);
                bus_driverRepository.deleteByIndex(i);
            }


        }
    }
  



    ofstream fout("Client.txt", ios_base::app);


    if (!fout)
    {
        cout << ("Can't open a file ");
        exit(1);
    }
    else {
        string firstName;
        string address;
        cout << "Enter the Name of the client: " << endl;
        cin >> firstName;



        cout << "Enter the Address of the client: " << endl;
        cin >> address;
        Client c(firstName, address);
        fout << firstName;
        fout << " ";
        fout << address;
        cout << "___You: " << firstName << ",on the street " << address << ",rented a taxi: " << nameoftaxi << " and added to base___" << endl;

    }



    fout.close();


}

void Command::showRate() {
    int max = car_driverRepository.GetEntity()[0].rate;
    int max2 = bus_driverRepository.GetEntity()[0].rate;
    int ind = 0;
    int ind2 = 0;
    for (int i = 1; i < car_driverRepository.GetEntity().size(); i++) {
        int tmp = car_driverRepository.GetEntity()[i].rate;
        if (max < (tmp)) {
            max = tmp;
            ind = i;
        }

    }
    for (int i = 1; i < bus_driverRepository.GetEntity().size(); i++) {
        int tmp = bus_driverRepository.GetEntity()[i].rate;
        if (max2 < (tmp)) {
            max2 = tmp;
            ind2 = i;
        }

    }
    if (bus_driverRepository.GetEntity()[ind2].rate > car_driverRepository.GetEntity()[ind].rate) {
        cout << "A driver with the highest rate is: " << endl << endl;

        bus_driverRepository.GetEntity()[ind2].Write();//virtual method no (*Driver)
        cout << endl;
    }
    else {
        cout << "A driver with the highest rate is: " << endl << endl;

        car_driverRepository.GetEntity()[ind].Write();//virtual method no (*Driver)
        cout << endl;

    }

}
void Command::changeRate() {

    int rating;
    string name;

    bool b;
    cout << "Enter 1 if you want to change rate for cars and 0 for buses: " << endl;
    cin >> b;
    cout << "Enter the name of a driver whose rating you want to change : " << endl;
    cin >> name;
    if (b) {
        for (int i = 0; i < car_driverRepository.GetEntity().size(); i++) {
            if ((car_driverRepository.GetEntity()[i]).name == name) {
                cout << "Enter a rating from 1-5 to this driver: " << endl;
                cin >> rating;
                car_driverRepository.changerate(i, rating);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < bus_driverRepository.GetEntity().size(); i++) {
            if ((bus_driverRepository.GetEntity()[i]).name == name) {
                cout << "Enter a rating from 1-5 to this driver: " << endl;
                cin >> rating;
                bus_driverRepository.changerate(i, rating);
                break;
            }
        }

    }


}


