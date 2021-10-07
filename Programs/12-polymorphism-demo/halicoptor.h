#pragma once
#include <iostream>
using namespace std;
#include "rideable.h"


namespace conceptarchitect:: rideimplementations{

    class Halicoptor:public Rideable{

        public:
        int averageCost(){
            return 800;
        }
        string ride(){
            return "fly in the air";
        }
    };
}



