#include <iostream>
#include "triangle.hpp"
using namespace std;

void test(Triangle *triangle, const char * prefix="Test Triangle"){
    if(!triangle){
        cout<<"invalid triangle"<<endl;
    }
    //we can safely use the triangle
    Triangle &t=*triangle; 
    t.show(prefix);
    cout<<"area ="<<t.area()<<endl
        <<"perimeter="<<t.perimeter()<<endl<<endl;
}






int main(int argc, char const *argv[])
{
    
    cout<<"sizeof(Triangle) = "<<sizeof(Triangle)<<endl;

   //Triangle t1={3,4,5};
   Triangle *t1= createTriangle(3,4,5);
   test(t1,"t1");

   //Triangle t2={3,4,12};
   Triangle *t2= createTriangle(3,4,12);
   test(t2,"t2");

    //Triangle t3={-1,2,2};
    Triangle *t3=createTriangle(-1,2,2);
    test(t3,"t3");

    return 0; //NORMAL SHUTDOWN WITHOUT ANY ERROR (0 ERROR)
}
