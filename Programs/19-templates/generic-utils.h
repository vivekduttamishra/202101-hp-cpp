#pragma once
#include <iostream>
#include <string.h>
using namespace std;

template<typename Data>
void Swap(Data & x , Data & y)
{
    Data t=x;
    x=y;
    y=t;
}


void Swap(char * x , char * y)
{
    char * t = new char[strlen(x)+1];
    strcpy(t,x);
    strcpy(x,y);
    strcpy(y,t);
    delete [] t;
    
}


template<class T>
void show(const char * prefix, const T &a, const T & b)
{
    cout<<prefix<<a<<"\t second is "<<b<<endl;
}


template<typename T>
void show(const char * prefix, const T * list, int size)
{
    cout<<prefix<<": ";
    for(int i=0;i<size;i++)
        cout<<list[i]<<"\t";

    cout<<endl;
}



template<typename number>
number divide(number nr, number dr){
    return nr/dr;
}


