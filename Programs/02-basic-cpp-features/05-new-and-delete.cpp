#include <iostream>

struct Triangle
{
    int s1, s2, s3;
};

int main(int argc, char const *argv[])
{
    int *a = new int; //allocate dynamic memory for a single int
    *a = 20;          //set a value of 20

    std::cout << "*a=" << *a << std::endl;

    Triangle *t = new Triangle;

    t->s1 = 3;
    t->s2 = 4;
    t->s3 = 5;

    std::cout << t->s1 << ","
              << t->s2 << ","
              << t->s3 << std::endl;

    //allocate memory for an array of values

    int * numbers= new int[5];  //allocate for 5 items.

    for(int i=0; i<5; i++)
        numbers[i]=i*5;

    for(int i=0; i<5; i++)
        std::cout<<numbers[i]<<"\t";

    std::cout<<std::endl;


    //you should free the memory using delete keyword
    delete a; //frees the memory for one value

    delete t; //free memory for one struct

    delete []numbers;  //free memory for an array

    return 0;
}
