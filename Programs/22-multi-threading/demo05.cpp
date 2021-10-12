#include <iostream>
#include <thread>
#include <string>
using namespace std;

void countDown(int max,string name){

    
    auto id= this_thread::get_id();

    cout<<"thread started:"<<id<<"#"<<name<<endl;
    
    while(max>=0){
        cout<<"["<<name<<"]:"<< max <<endl;
        max--;
    }
    cout<<"thread ends:"<<name<<endl;
}

int main(int argc, char const *argv[])
{
    
    auto t1=thread(countDown,20,"c20");
    auto t2=thread(countDown,40,"c40");
    
    

    cout<<"["<<this_thread::get_id()<<"]:"<<"waiting for thread to finish"<<endl;
    
    t1.join();
    t2.join();
    
    cout<<"["<<this_thread::get_id()<<"]:"<<"thread finished"<<endl;


    return 0;
}