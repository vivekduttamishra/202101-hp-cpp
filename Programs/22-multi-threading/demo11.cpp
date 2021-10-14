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

thread* factorialPromise(int x, promise<int> &myPromise){
    
    

    thread *t =new thread([&myPromise,x](){

        auto fx=factorial(x);
        myPromise.set_value(fx);  // here is the promised result

    });

    
    return t;
}


int permutation(int n, int r){


    promise<int> fnp, fn_rp;

    auto fn= fnp.get_future();
    auto fn_r=fn_rp.get_future();



    auto fnt= factorialPromise(n,fnp); 

    auto fn_t=factorialPromise(n-r,fn_rp);  
    
    
    fnt->join();
    fn_t->join();

  
    return fn.get()/ fn_r.get();


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

