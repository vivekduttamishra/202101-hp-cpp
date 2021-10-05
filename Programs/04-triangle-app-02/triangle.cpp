#include <iostream>
#include "triangle.h"
#include <math.h>
using namespace std;


Triangle*  createTriangle(double s1,double s2,double s3){
    
    Triangle * t= new Triangle;
    t->s1=s1;
    t->s2=s2;
    t->s3=s3;

    if(isValid(*t))
        return t;
    else{
        delete t; //it was not a valid triangle
        return NULL;
    }    


    

}

double perimeter(const Triangle &t)
{

    //  if(!(t.s1+t.s2>t.s3 && t.s2+t.s3>t.s1 && t.s1+t.s3>t.s2)){
    //     cout<<"invalid triangle details"<<endl;
    //     return NAN;
    // }

    if (isValid(t))
        return t.s1 + t.s2 + t.s3;
    else
        return NAN;
}

double area(const Triangle &t)
{
    //    if(!(t.s1+t.s2>t.s3 && t.s2+t.s3>t.s1 && t.s1+t.s3>t.s2)){
    //         cout<<"invalid triangle details"<<endl;
    //         return NAN;
    //     }
    double s = perimeter(t) / 2.0;
    if (s == NAN)
        return s;
    else
        return sqrt(s * (s - t.s1) * (s - t.s2) * (s - t.s3));
}

void show(const Triangle &t, const char *prefix)
{
    //    if(!(t.s1+t.s2>t.s3 && t.s2+t.s3>t.s1 && t.s1+t.s3>t.s2)){
    //         cout<<"invalid triangle details"<<endl;
    //         return ;
    //     }

    if (isValid(t))
    {
        cout << prefix << " : <"
             << t.s1 << ","
             << t.s2 << ","
             << t.s3 << ">\n";
    }
    else
    {
        cout << "<invalid triangle>" << endl;
    }
}