#pragma once
#include <iostream>
using namespace std;
#include "rideable.h"

namespace matherantransport
{

    class Horse : public Rideable
    {

    public:
        int averageCost()
        {
            return 15;
        }
        string ride()
        {
            return "ride on it's back!";
        }
    };

}
