#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char const *argv[])
{
    
    auto t1= thread([](){
        cout<<"welcome to new thread"<<endl;
    });
    
    cout<<"Hello from main thread"<<endl;

    return 0;
}