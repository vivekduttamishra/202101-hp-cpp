#include <stdio.h>
#include <iostream>
using namespace std;
#include "animals.h"


int main(){

   
    Animal * animals[]={

        //new Animal,
        new Tiger,
        new Fish,
        NULL
    };

    for(int i=0;animals[i]; i++)
    {
        animals[i]->move();
        animals[i]->eat();

        //animals[i]->hunt();  //no all animals hunt

        //Tiger * tiger= animals[i];  //animals[i] may even be a fish

        //we can maually typecast
        //Tiger * tiger = (Tiger *) animals[i];

        Tiger * tiger = dynamic_cast<Tiger *>(animals[i]);
        if(tiger!=NULL)
            tiger->hunt();
        cout<<endl<<endl;
        
    }
    
    
    return 0;
}