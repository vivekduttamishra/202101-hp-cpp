#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

#include "car.h"
#include "halicoptor.h"

using namespace conceptarchitect::rideimplementations;


namespace ola::rideapp{


class RideManager{

public:

    void rent(Car * car, int distance){

        cout<<"your ride "<<typeid(*car).name()<<endl;
        cout<<car->ride()<<endl;
        cout<<"total cost of ride is "<< distance*car->averageCost()* 1.2<<endl<<endl; //20% commission
    }

    void rent(Halicoptor * halicoptor, int distance){

        cout<<"your ride "<<typeid(*halicoptor).name()<<endl;
        cout<<halicoptor->ride()<<endl;
        cout<<"total cost of ride is "<< distance*halicoptor->averageCost()* 1.2<<endl<<endl; //20% commission
    }

    //any new type of ride will require a new overload
    //thus chaning this class.

};



}

