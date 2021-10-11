#include <stdio.h>
#include <iostream>
#include <exception>
#include <string>
#include <time.h>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;
#include "utils.h" //isPrime



int main(){

    LinkedList<int> numbers;

    numbers<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10;
    cout<<"numbers: "<<numbers<<endl;

    LinkedList<string> names;
   
    names<<"india"<<"france"<<"japan";

    cout<<"names: "<<names<<endl;


   
    return 0;
}