#include <iostream>
using namespace std;

struct Point3d{
    int x,y,z;
};

int main(int argc, char const *argv[])
{

    Point3d pt{3,4,5};

    //what if I need to get the value of x and y from pt;
    
    //traditional method
    // auto x=pt.x;
    // auto y=pt.y;

    //new syntax
    auto [x,y,z] = pt; 

    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    
    
    
    return 0;
}