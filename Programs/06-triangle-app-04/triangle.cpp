#include <iostream>
#include "triangle.hpp"

using namespace std;


//Triangle*  createTriangle(double s1,double s2,double s3){

Triangle* Triangle::createTriangle(double s1,double s2,double s3){
    
    //Triangle * this= new Triangle; // we have the object

   if( s1 > 0 && s2 > 0 && s3 > 0 && 
                s1 + s2 > s3 && 
                s2 + s3 > s1 && 
                s1 + s3 > s2) 
    {

        this->s1=s1;
        this->s2=s2;
        this->s3=s3;
    } else {
        //which s1 is getting set to NAN? argument or member
        this->s1 = NOT_A_NUMBER; //marks triangle as invalid
    }

    return this;

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