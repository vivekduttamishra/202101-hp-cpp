#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <chrono>
using namespace std;

int factorial(int i){ 
        int f=1;
        int z=i;
        while(i>=1){
            f*=i--;
         //   cout<<this_thread::get_id()<<"->"<<f<<endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        
        return f;
}




int permutation(int n, int r){

    auto fn = async(factorial,n);  //call factorial(n) on a separate thread

    auto fn_r=async(factorial, n-r); //call factorial(n-r) on a spearate thrad



    return fn.get()/fn_r.get();  //automatically wait for the result


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

