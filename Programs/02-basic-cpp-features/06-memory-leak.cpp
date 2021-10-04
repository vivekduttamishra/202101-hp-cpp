#include <iostream>
using namespace std;

int callMe(){

    int * numbers=new int[10000];
    //if we don't delete this memory, it will be a memory leak once the function ends
    delete [] numbers; //delete number may work or may not work. It may vary with c++ version and compiler.
}


int main(int argc, char const *argv[])
{
    int i=0;
    while(true){
        callMe();
        i++;
        if(i%100==0)
            cout<<" + ";
    }


    return 0;
}