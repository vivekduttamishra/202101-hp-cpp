#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace conceptarchitect::ridespecs{

    class Rideable{

        public:
        virtual int averageCost(){
            return 0;
        }
        virtual string ride(){
            return "ride on!";
        }
    };

};


