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

    int data[]={2,3,9,11,8,2,5};

    LinkedList<int> numbers;

    forEach( data, data+7, [&numbers](auto d){numbers.add(d);});


    cout<<"numbers: "<<numbers<<endl;


    auto result = search( begin(numbers), end(numbers), [](auto number){ return number>5;});

    for(auto value : result)
        cout<< value<<endl;

    return 0;
}