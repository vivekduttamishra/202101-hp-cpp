#pragma once

struct Triangle{
    double s1,s2,s3;
};

double perimeter(const Triangle &t1);

double area(const Triangle &t1);

void show(const Triangle &t1, const char * prefix="Triangle"); 

inline bool isValid(const Triangle &t){
    return t.s1>0 && t.s2>0 && t.s3>0 && t.s1+t.s2>t.s3 && t.s2+t.s3>t.s1 && t.s1+t.s3>t.s2;
}

Triangle*  createTriangle(double s1,double s2, double s3);