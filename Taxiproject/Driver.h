#pragma once
#include <iostream>
#include <string>

using namespace std;
//Component
class Driver
{
public:
 
    virtual void Info_Elem() = 0;
    virtual ~Driver() { }

};


// ConcreteComponent
template <class T>
class SimpleDriver : public Driver
{
private:
    T tmp;

   
public:
    SimpleDriver(T tmp) {
        this->tmp = tmp;
    }


    virtual void Info_Elem()
    {
        tmp.Write();
    }

};
//Decorator
class driverDecorator : public Driver
{
private:
    Driver& m_Decorator;
public:
    driverDecorator(Driver& decorator) :m_Decorator(decorator)
    {

    }

   
    virtual void Info_Elem()
    {
        m_Decorator.Info_Elem();
    }
};



// ConcreteDecoratorA
class driver_car_decorator : public driverDecorator
{

public:
    driver_car_decorator(Driver& decorator) :driverDecorator(decorator)
    {

    }
 
    virtual void Info_Elem()
    {
        cout << " _____AVAILABLE CAR DRIVER______: " << endl;
        driverDecorator::Info_Elem();

    }

};
//ConcreteDecoratorB
class driver_bus_decorator : public driverDecorator
{

public:
    driver_bus_decorator(Driver& decorator) :driverDecorator(decorator)
    {

    }

  
    virtual void Info_Elem()
    {
        cout << " ____AVAILABLE BUS DRIVER_____: " << endl;
        driverDecorator::Info_Elem();

    }

};




