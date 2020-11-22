#include "Command.h"
#include "Taxi.h"

#include "Client.h"
#include "Repository.h"
#include <iostream>
#include <algorithm>
#include <fstream>

#include <string>



void Command::AddTaxi(Taxi& taxi)
{
    taxiRepository.Add(taxi);
}

void Command::AddDriver(Driver& driver)
{
    driverRepository.Add(driver);
}

void Command::Print() {

    for (int i = 0; i < taxiRepository.GetEntity().size(); i++) {

        taxiRepository.GetEntity()[i].Write();

    }

}

void Command::WriteAllDrivers() {


    for (int i = 0; i < driverRepository.GetEntity().size(); i++) {
        driverRepository.GetEntity()[i].Write();
        cout << endl;

        taxiRepository.GetEntity()[i].Write();




    }
}

void Command::showRate() {
    int max = driverRepository.GetEntity()[0].rate;
    int ind = 0;
    for (int i = 1; i < driverRepository.GetEntity().size(); i++) {
        int tmp = driverRepository.GetEntity()[i].rate;
        if (max < (tmp)) {
            max = tmp;
            ind = i;
        }

    }
    cout << "A driver with the highest rate is: " << endl << endl;

    driverRepository.GetEntity()[ind].Write();//virtual method no (*Driver)
    cout << endl;
}
void Command::changeRate() {
    cout << "Enter the name of a driver whose rating you want to change : " << endl;
    int rating;
    string name;
    cin >> name;
    for (int i = 0; i < driverRepository.GetEntity().size(); i++) {
        if ((driverRepository.GetEntity()[i]).name == name) {
            cout << "Enter a rating from 1-5 to this driver: " << endl;
            cin >> rating;
            driverRepository.GetEntity()[i].rate = rating;
            break;
        }
    }


}
