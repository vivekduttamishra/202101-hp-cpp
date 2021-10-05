#pragma once
#include <math.h>

#define NOT_A_NUMBER -1

struct Triangle
{ 
    double s1, s2, s3;
    

    //implicit inline function
    bool isValid() const
    {
        // return s1 > 0 && s2 > 0 && s3 > 0 && 
        //         s1 + s2 > s3 && 
        //         s2 + s3 > s1 && 
        //         s1 + s3 > s2;

        bool result=s1!=NOT_A_NUMBER;  //triangle is valid
        return result;
    }

    //functions are declared outside
    void show(const char *prefix = "Triangle") const;

    double perimeter();

    double area();

    Triangle(double s1,double s2, double s3){
        createTriangle(s1,s2,s3);
    }

    //doubles as 0 argument constructor
    Triangle(double side=1){
        createTriangle(side,side,side);
    };

    // Triangle(){
    //     createTriangle(1,1,1);
    // }

    // object must exist to call it.
    Triangle * createTriangle(double s1, double s2, double s3);
    
};

//Triangle *createTriangle(double s1, double s2, double s3);