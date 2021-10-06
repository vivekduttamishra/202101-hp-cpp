
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


class Rideable{

    public:
    int averageCost(){
        return 0;
    }
    virtual string ride(){
        return "ride on!";
    }
};

class Car:public Rideable{

    public:
    int averageCost(){
        return 8;
    }
    string ride(){
        return "runs on petrol";
    }
};



class Halicoptor:public Rideable{

    public:
    int averageCost(){
        return 800;
    }
    string ride(){
        return "fly in the air";
    }
};


class RideAggregator{

public:

    void rent(Rideable * rideable, int distance){

        cout<<"your ride "<<typeid(*rideable).name()<<endl;
        cout<<rideable->ride()<<endl;
        cout<<"total cost of ride is "<< distance*rideable->averageCost()* 1.2<<endl<<endl; //20% commission
    }

};


int main(int argc, char const *argv[])
{
    RideAggregator uber;

    uber.rent( new Car(), 20);
    uber.rent(new Halicoptor(), 200);
    return 0;
}



