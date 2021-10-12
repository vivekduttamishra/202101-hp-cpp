#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;

class Factorial
{
    private:
    int x;     int fx=0;
    thread *t;
    

    public:
    Factorial(int x){
        this->x=x;
        t=new thread( [this](){
            this->fx = factorial(this->x);
          
        });
    };

    ~Factorial(){
        delete t;
    }

    int result(){
        wait();
        return fx;
    }

    thread * getThread(){return t;}

    void wait(){
      
        t->join();
    }

    static int factorial(int i){ 
        int f=1;
        int z=i;
        while(i>=1){
            f*=i--;
            //cout<<this_thread::get_id()<<"->"<<f<<endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        
        return f;
    }


};


int permutation(int n, int r){
   
    auto fn=Factorial(n);

    auto fn_r=Factorial(n-r);

    //fn.getThread()->join();
    //fn_r.getThread()->join();

    //fn.wait();
    //fn_r.wait();
   

    return fn.result()/fn_r.result();   
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

