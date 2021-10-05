#include <iostream>
#include "triangle.hpp"
using namespace std;

void test(Triangle *triangle, const char * prefix="Test Triangle"){
    if(triangle==NULL || !triangle->isValid()){
        cout<<"invalid triangle "<<prefix<<endl;
        return;
    }
    
    triangle->show(prefix);
    cout<<"area ="<<triangle->area()<<endl
        <<"perimeter="<<triangle->perimeter()<<endl<<endl;
}






int main(int argc, char const *argv[])
{

    Triangle t1(3,4,5);

    test(&t1,"t1");

    t1.s3=15;  //i can add any invalid value here

    test(&t1,"t1 after modification");





    return 0; //NORMAL SHUTDOWN WITHOUT ANY ERROR (0 ERROR)
}
