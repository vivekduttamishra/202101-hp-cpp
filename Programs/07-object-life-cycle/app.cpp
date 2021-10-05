#include <stdio.h>
#include <iostream>
#include "my-object.h"


//copy constructor will be called
void callMe(MyObject x){

    static MyObject sObj("callMe static object");
    x.value="valued modified in callMe";
    cout<<"callMe ends"<<endl;
}
//no copy contructor needed here.
void callMeRef(const MyObject & x){
    cout<<"in callMeRef: "<<x.value<<endl;
}
MyObject gObj1("global object 1");
static MyObject sgObj("static global object");
MyObject gObj2("global object 2");

int main(){

    cout<<"main function starts..."<<endl;
    MyObject mainObj1("Main Object 1");
    MyObject mainObj2("Main Object 2");
    static MyObject main("Main Static Object");

    MyObject * p1= new MyObject("Dynamic Object 1");
    MyObject * p2= new MyObject("Dynamic Object 2");

    for(int i=0;i<3;i++)
    {
        MyObject obj3("for loop call me param");
        callMe(obj3);
        callMeRef(obj3);
        //obj3 should be destroyed at the end of this block 3 times once in each loop
    }

    delete p1;
    cout<<"main function ends..."<<endl;


    return 0;
}

//destructor of globals shall be called after the end of main
//p2 destructor will never be called as no delete is called for items
//block object should be deleted by the end of the block object