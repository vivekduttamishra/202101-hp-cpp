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

    //t1.createTriangle(3,4,5) ;

    test(&t1,"t1");

    Triangle t2=Triangle(3,4,12);
    //t2.createTriangle(3,4,12);

    
    test(&t2,"t2");


    Triangle *t3=new Triangle(1,1,1);

    test(t3,"t3");


    Triangle t4(6);  //one arg constructor
    test(&t4,"t4");


    Triangle t5=7;  //implicit one arg constructor call 
    test(&t5,"t5");

    Triangle t6; //calls user defined 0 arg constructor

    test(&t6,"t6");


    delete t3; //should delete any memory allocated using new

    return 0; //NORMAL SHUTDOWN WITHOUT ANY ERROR (0 ERROR)
}
