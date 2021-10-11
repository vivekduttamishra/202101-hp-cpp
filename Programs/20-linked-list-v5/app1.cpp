#include <stdio.h>
#include <iostream>
#include <exception>
#include <string>
#include <time.h>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;
#include "utils.h" //isPrime
#include "algorithm.h"

template<typename T>
void printWide(T value){
    cout<<value<<"\t";
}

int main(){

    LinkedList<int> numbers;

    numbers<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10;
    cout<<"numbers: "<<numbers<<endl;

    LinkedList<string> names;
   
    names<<"india"<<"france"<<"japan";

    //cout<<"names: "<<names<<endl;

    forEach( names.begin(), names.end(), printWide<string>);


    int arr[]={2,3,5,9,7};

    //we can loop through the normal array also using forEach
    cout<<endl;
    forEach(arr, arr+4, printWide<int>); // 2,3,5 9 <--- stops on address of 7

    cout<<endl;


    return 0;
}