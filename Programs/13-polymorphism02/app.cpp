#include <stdio.h>
#include <iostream>
using namespace std;
#include "animals.h"


int main(){

   
    Animal * animals[]={

        new Animal,
        new Tiger,
        new Fish,
        NULL
    };

    for(int i=0;animals[i]; i++)
    {
        animals[i]->move();
        animals[i]->eat();

        cout<<endl<<endl;
        
    }
    
    
    return 0;
}