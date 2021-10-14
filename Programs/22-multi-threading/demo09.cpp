#include <iostream>
#include <chrono>
#include "worker-basket.h"
using namespace std;
using namespace std::chrono;
using namespace std::literals;
using namespace workerapi;


template<typename _Worker=Worker, typename _Basket=Basket>
inline void simulate(string name,int workerCount, int jobPerWorker, bool useSameBasket=false){

    _Basket *commonBasket=new _Basket; //if we are sharing a basket
    
    cout<<"starting simulation "<<name<<"\tworkers:"<<workerCount<<"\tjob:"<<jobPerWorker<<endl;

    vector<_Worker*> workers;

    for(int i=0;i<workerCount;i++){
        _Basket * basket= useSameBasket ? commonBasket : new _Basket;
        auto worker= new _Worker{basket, jobPerWorker};
        workers.push_back(worker);
    }

    cout<<"worker added. now starting them"<<endl;

    auto start=  system_clock::now();

    for_each(workers.begin(), workers.end(),[] (auto worker){worker->start();});

    cout<<"workers started. now waiting for them to finish"<<endl;

    for_each(workers.begin(), workers.end(),[] (auto worker){worker->wait();});

    auto end= system_clock::now();

    cout<<"please wait for the result"<<endl;
    long totalWorkDone=0;

    if(!useSameBasket){

        for_each(workers.begin(), workers.end(),[&totalWorkDone](auto worker){ 
                    totalWorkDone+=worker->basket->items;
                    });
    } else {
        totalWorkDone=commonBasket->items;
    }

    auto timeTaken= end.time_since_epoch().count() -start.time_since_epoch().count();
    //time_point.time_since_epoch().count()


    cout<<"total work done :"<<totalWorkDone<<endl;
    cout<<"total time taken is :" << timeTaken/1000<<endl<<"us"<<endl;
    cout<<endl<<endl;
}


int main(int argc, char const *argv[])
{
   
   simulate<workerapi::v1::Worker,workerapi::v1::Basket>("Different Thread Unsafe Basket",1000,10000,false);
   simulate<workerapi::v1::Worker,workerapi::v1::Basket>("Common Thread Unsafe Basket",1000,10000,true);
   
    simulate<workerapi::v2::Worker,workerapi::v2::Basket>("Different Thread safe Basket",1000,10000,false);
   simulate<workerapi::v2::Worker,workerapi::v2::Basket>("Common Thread Safe Basket",1000,10000,true);
   


    simulate("Different  Thread UnSafe Basket", 1000, 10000, false);   
    simulate("Common Basket Thread UnSafe Basket", 1000, 10000, true);   

    return 0;
}