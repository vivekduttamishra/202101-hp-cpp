#pragma once
#include <iostream>
#include <string>
using namespace std;

struct MyObject{

    string  value;

    MyObject(string value="default") 
    {
        cout<<"MyObject::MyObject("<<value<<") called"<<endl;
        this->value=value;
    }

    MyObject(const MyObject& other)
    {
        cout<<"Copy Constructor Called with MyObject("<<other.value<<")"<<endl;
        value=other.value;
    }

    ~MyObject(){

        cout<<"Destructor called for MyObject("<<value<<")"<<endl;

    }
};