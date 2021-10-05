#include <iostream>
#include "triangle.h"
using namespace std;

void test(Triangle *triangle, const char * prefix="Test Triangle"){
    if(!triangle){
        cout<<"invalid triangle"<<endl;
    }
    //we can safely use the triangle
    Triangle &t=*triangle; 
    show(t,prefix);
    cout<<"area ="<<area(t)<<endl
        <<"perimeter="<<perimeter(t)<<endl<<endl;
}

int main(int argc, char const *argv[])
{
    
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
