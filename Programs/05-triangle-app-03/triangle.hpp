#pragma once

struct Triangle
{
    double s1, s2, s3;

    //implicit inline function
    bool isValid() const
    {
        return s1 > 0 && s2 > 0 && s3 > 0 && 
                s1 + s2 > s3 && 
                s2 + s3 > s1 && 
                s1 + s3 > s2;
    }

    //functions are declared outside
    void show(const char *prefix = "Triangle") const;

    double perimeter();

    double area();
};

Triangle *createTriangle(double s1, double s2, double s3);