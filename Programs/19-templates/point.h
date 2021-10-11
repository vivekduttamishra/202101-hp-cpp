#pragma once
#include <iostream>
using namespace std;

struct Point{
    int x,y;    
};

inline ostream & operator<<(ostream & os, const Point & p){
    return os<<"Point("<<p.x<<","<<p.y<<")";
};
