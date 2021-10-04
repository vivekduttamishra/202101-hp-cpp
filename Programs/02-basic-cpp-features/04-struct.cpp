#include <iostream>


struct Triangle{
    int s1,s2,s3;
};


int main(int argc, char const *argv[])
{
    //unike c, we don't need to use the word 'struct' while using 'Triangle'
    //you don't need a typedef here
    Triangle t={3,4,5};

    std::cout<< t.s1<<","
            << t.s2<<","
            <<t.s3<< std::endl;
    
    return 0;
}