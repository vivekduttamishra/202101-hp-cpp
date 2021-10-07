#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;
#include "rideable.h"

using namespace conceptarchitect::ridespecs;

namespace uber::app
{

    class RideAggregator
    {

    public:
        void rent(Rideable *rideable, int distance)
        {

            cout << "your ride " << typeid(*rideable).name() << endl;
            cout << rideable->ride() << endl;
            cout << "total cost of ride is "
                 << distance * rideable->averageCost() * 1.2 //20% commission
                 << endl
                 << endl;
        }
    };

}
