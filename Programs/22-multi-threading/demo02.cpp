#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char const *argv[])
{
    
    auto t1= thread([](){
        cout<<"welcome to new thread"<<endl;
    });
    
    
    
    cout<<"Hello from main thread"<<endl;

    cout<<"waiting for thread to finish"<<endl;
    t1.join();
    cout<<"thread finished"<<endl;


    return 0;
}