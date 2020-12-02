#pragma once
#include <iostream>
#include <string>

using namespace std;
//Component
class Taxi
{
public:
    virtual void Info() = 0;
    virtual void Info_Elem() = 0;
    virtual ~Taxi() { }

};


// ConcreteComponent
template <class T>
class SimpleTaxi : public Taxi
{
private:
    vector<T> arr;
    T tmp;
   
public:
    SimpleTaxi(vector<T> arr) {
        this->arr = arr;
    }
    SimpleTaxi(T tmp) {
        this->tmp = tmp;
    }
    virtual void Info()
    {
        for (int i = 0; i < arr.size(); i++) {

            arr[i].Write();

        }
    }
    virtual void Info_Elem() {
        tmp.Write();
    }
  
};
//Decorator
class taxiDecorator : public Taxi
{
private:
    Taxi& m_Decorator;//abs class
public:
    taxiDecorator(Taxi& decorator) :m_Decorator(decorator)
    {

    }

    virtual void Info()
    {
        m_Decorator.Info();
    }
    virtual void Info_Elem()
    {
        m_Decorator.Info_Elem();
    }
};



// ConcreteDecoratorA
class carTaxi : public taxiDecorator
{

public:
    carTaxi(Taxi& decorator) :taxiDecorator(decorator)
    {

    }
    virtual void Info()
    {
        cout << " ____AVAILABLE CARS___: " << endl;
        taxiDecorator::Info();

    }
    virtual void Info_Elem()
    {
        cout << " ___AVAILABLE CAR____: " << endl;
        taxiDecorator::Info_Elem();

    }


};
//ConcreteDecoratorB
class busTaxi : public taxiDecorator
{

public:
    busTaxi(Taxi& decorator) :taxiDecorator(decorator)
    {

    }

    virtual void Info()
    {
        cout << " ___AVAILABLE BUSES___: " << endl;
        taxiDecorator::Info();
    }
    virtual void Info_Elem()
    {
        cout << " ___AVAILABLE BUS___: " << endl;
        taxiDecorator::Info_Elem();

    }

};




