#include <iostream>
#include <math.h>

double power(double x, double exp=0.5);

int main(){
    std::cout<<power(4,2)<<std::endl
            <<power(4)<<std::endl;

   
    return 0;
}

double power(double x, double exp){
    return pow(x,exp);
}