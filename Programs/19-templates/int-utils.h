#pragma once
#include <iostream>
using namespace std;

void swap(int & x , int & y){
    int t=x;
    x=y;
    y=t;
}

void show(const char * prefix, const int &a, const int & b)
{
    cout<<"before swap first is "<<a<<"\t second is "<<b<<endl;
}