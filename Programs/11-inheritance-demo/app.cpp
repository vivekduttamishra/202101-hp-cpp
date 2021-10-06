#include <iostream>
using namespace std;


class X
{
    //fields
    int a;    
    public:
        X(int a){
            //initialize fields
            cout<<"X::X("<<a<<") called"<<endl;
            this->a=a;
        }

        //Methods
        int getA(){return a;}
        void setA(int a){this->a=a;}
        void use(){ cout<<"using X::use() with "<<a<<endl;}
};

class Y : public X {

    int b;

    public:
    int getB(){return b;}
    void setB(int b){this->b=b;}

    Y(int a=1, int b=0)  :  X(a)
    {
        cout<<"Y::Y("<<b<<") called"<<endl;
        this->b=b;
    }

    void use(){
        cout<<"Using Y::use() with a "<< getA() <<" and b "<<b<<endl;
    }

};

int main(){

    Y y(5,20);   //  Y(20) called  -->  X() executes --->    Y() executes

    y.use();

    return 0;
}

int test1(){

    X x(5);

    //X x2= x.X(); //object x doesn't have X()


    x.use();

    x.setA(20);

    x.use();


    Y y;   //contains inherited 'a' and own 'b'

    cout<<"sizeof(y):"<<sizeof(y)<<endl;

    y.use();

    y.setA(50);

    y.use();

    y.setB(100);

    cout<<"y.getB():\t"<<y.getB();

}