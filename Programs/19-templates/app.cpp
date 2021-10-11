#include <stdio.h>
#include <iostream>
#include <string>
#include "couple.h"
using namespace std;

#include "generic-utils.h"
#include "point.h"


int main(){

    int i=10, j=20;

    show("before swap", i, j);  //generate show for Data=int

    Swap(i,j);      //generate swap for Data=int

    show("after swap", i, j);  //reuse show for data=int

    
    Point p1={3,4}, p2={5,9};  

   

    show("before swap", p1, p2 ); //generate show for data=Point

    Swap(p1,p2);  //genrate show for data=Point

    show("after swap",p1,p2);  //reuse show for data=Point







    cout<<"divide(7,2) = "<<divide(7,2)<<endl;  //divide(int,int)
    
    cout<<"divide(7.0,2.5) = "<<divide(7.0,2.0)<<endl; //divide(double,double)

   // cout<<"divide(7,2.0) = "<<divide(7,2.0)<<endl; //ambigous int or double?

   cout<<"divide<double>(7,2) = "<<divide<double>(7,2)<<endl; //divide(double,double)
   
    const char * names[]={"india","usa","france","germany"};

    int values[]= {1,2,3};

    show("names", names, 4);

    show("values",values,3);
    

    string s1="India";

    string s2="Japan";

    show("before swap", s1,s2);
    Swap(s1,s2);
    show("after swap",s1,s2);


    char name1[]= "INDIA";
    char name2[]= "FRANCE";
    cout<<"before swap name1="<<name1<<"\tname2="<<name2<<endl;
    Swap(name1,name2);
    cout<<"after swap name1="<<name1<<"\tname2="<<name2<<endl;

    Couple<int,int> pt(2,3);

    cout<<"pt is "<<pt<<endl;

    Couple<string,int> code("IN",91);

    cout<<"code is "<<code<<endl;



    return 0;
}