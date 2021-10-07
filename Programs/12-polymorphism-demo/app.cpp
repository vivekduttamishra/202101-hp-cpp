
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
#include "ride-aggregator.h"
 #include "ride-manager.h"

//client need to know exact implementation
#include "car.h"
#include "halicoptor.h"
#include "horse.h"

using namespace ola::rideapp;
using uber::app::RideAggregator; //just get one class from namespace
using matherantransport::Horse; //just get the horse not whole namespace

int main(int argc, char const *argv[])
{
    RideAggregator uber;
    uber.rent( new Car(), 20);
    uber.rent(new Halicoptor(), 200);
    uber.rent(new Horse, 5);


    RideManager ola;
    ola.rent(new Car(),20);
    ola.rent(new Halicoptor(),200);
    //ola.rent(new Horse(), 5);
    return 0;
}



