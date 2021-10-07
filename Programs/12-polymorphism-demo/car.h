#pragma once
#include <iostream>
using namespace std;
#include "rideable.h"

using namespace conceptarchitect::ridespecs;

namespace conceptarchitect{

    namespace rideimplementations{

        class Car:public Rideable{

            public:
            int averageCost(){
                return 8;
            }
            string ride(){
                return "runs on petrol";
            }
        };


    }

}




