#include <iostream>
#include "triangle.hpp"
#include <math.h>
using namespace std;


Triangle*  createTriangle(double s1,double s2,double s3){
    
    Triangle * t= new Triangle;
    t->s1=s1;
    t->s2=s2;
    t->s3=s3;

    if(t->isValid())
        return t;
    else{
        delete t; //it was not a valid triangle
        return NULL;
    }      

}

double Triangle::perimeter()
{
    if (this->isValid())
        return this->s1 +this-> s2 + this-> s3;
    else
        return NAN;
}

double Triangle::area()
{
    double s = perimeter() / 2.0;
    if (s == NAN)
        return s;
    else
        return sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

void Triangle::show(const char *prefix) const
{
 
    //isValid should also be a const to keep our promise
    if (isValid())
    {
        cout << prefix << " : <"
             << s1 << ","
             << s2 << ","
             << s3 << ">\n";
    }
    else
    {
        cout << "<invalid triangle>" << endl;
    }
}