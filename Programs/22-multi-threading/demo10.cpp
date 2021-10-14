#include <iostream>
using namespace std;
#include "smartobj.h"
void callMe(){

    //int * ptr=new int[100000];

    SmartPointer<int> ptr=new int [100000];

    //even if I forget to call delete destructor of SmartPointer will do it
}


int main(int argc, char const *argv[])
{
    int i=0;
    while(true){
    
        callMe();
        i++;
        if(i%1000==0)
            cout<<" + ";
    }
    return 0;
}