#include <iostream>
using namespace std;


int_fast16_t increment( int * p,int delta=1){
    
    *p=*p+delta;
    
    return *p;
}

int increment( int &p, int delta=1){
   
    p=p+delta;

    return p;
}

int main(){

    int x=20;

    cout<< increment(&x) <<endl;  //21`
    cout<< increment(&x,5) <<endl;  //26

    cout<< increment(x) <<endl;    //27

    cout<< increment(x,10) <<endl; //37

    cout<< x<< endl;               //37

}