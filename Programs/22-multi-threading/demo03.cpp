#include <iostream>
#include <thread>
using namespace std;

void countDown(){

    
    auto id= this_thread::get_id();

    cout<<"thread started:"<<id<<endl;
    int max=100;
    while(max>=0){
        cout<<"["<<id<<"]:"<< max <<endl;
        max--;
    }
    cout<<"thread ends:"<<id<<endl;
}

int main(int argc, char const *argv[])
{
    
    auto t1=thread(countDown);
    auto t2=thread(countDown);
    
    

    
    

    cout<<"["<<this_thread::get_id()<<"]:"<<"waiting for thread to finish"<<endl;
    
    t1.join();
    t2.join();
    
    cout<<"["<<this_thread::get_id()<<"]:"<<"thread finished"<<endl;


    return 0;
}