#include <iostream>
#include <thread>

#include <string>
#include <chrono>
using namespace std;

void countDown(int max,string name){

    
    auto id= this_thread::get_id();

    cout<<"thread started:"<<id<<"#"<<name<<endl;
    
    while(max>=0){
        cout<<"["<<name<<"]:"<< max <<endl;
        std::this_thread::sleep_for(chrono::milliseconds(1000)); //this thread will not run for next 500ms
        max--;
    }
    cout<<"thread ends:"<<name<<endl;
}

int main(int argc, char const *argv[])
{
    
    auto t1=thread(countDown,20,"c20");
    auto t2=thread(countDown,30,"c40");
    
    

    cout<<"["<<this_thread::get_id()<<"]:"<<"waiting for thread to finish"<<endl;
    
    t1.join();
    t2.join();
    
    cout<<"["<<this_thread::get_id()<<"]:"<<"thread finished"<<endl;


    return 0;
}