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

    LinkedList<int> numbers{2,3,9,11,8,2,5};


    cout<<"numbers: "<<numbers<<endl;





    return 0;
}