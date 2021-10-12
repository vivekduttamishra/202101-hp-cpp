#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;

int factorial(int i){ 
        int f=1;
        int z=i;
        while(i>=1){
            f*=i--;
            cout<<this_thread::get_id()<<"->"<<f<<endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        
        return f;
}


int permutation(int n, int r){
    int fn=1,fn_r=1;
    
    auto t1= thread([&fn](auto n) { fn=factorial(n);}, n);  // n is passed by the thread to function

    auto t2= thread([&fn_r,n,r](){ fn_r = factorial(n-r);});  //n is captured 

    t1.join();
    t2.join();

    return fn/fn_r;


}

int main(int argc, char const *argv[])
{
    int n=7;
    int r=2;
    cout<<"calculating the permutation..."<<endl;

    int per=permutation(n,r);

    cout<<n<<"P"<<r<<"="<<per<<endl;
    return 0;
}

