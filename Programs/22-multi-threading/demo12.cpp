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


    packaged_task<int(int)> fnt ( factorial   );

    packaged_task<int(int)> fnrt( factorial );
   
    auto fnf= fnt.get_future();

    auto fnrf=fnrt.get_future();

    thread t1(move(fnt), n);
    thread t2(move(fnrt), n-r);

    t1.join();
    t2.join();

    return fnf.get()/fnrf.get();


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

