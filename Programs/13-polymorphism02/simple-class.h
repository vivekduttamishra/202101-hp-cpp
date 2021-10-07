#pragma once
#include <iostream>
using namespace std;



struct Empty{
    //byte dummy   //added by compiler to make it non 0
    
    void show(){
        cout<<"I am empty"<<endl;
    }
};

class ConstantInteger{
    //no dummy byte added
    const int value;
    public:
    ConstantInteger(int x)  : value(x)
    {
        //this->value=x;  //tyring to modify a const after creation
    }

    int getValue() const {return value;}
};