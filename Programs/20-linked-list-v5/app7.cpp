#include <iostream>

using namespace std;

long operator ""_hrs (unsigned long long hrs){
    return hrs*60*60*1000;
}

// `unsigned long long` parameter required for integer literal.
long long operator "" _celsius(unsigned long long tempCelsius) {

  return tempCelsius * 18/10 + 32;
}
//24_celsius; // == 75



int main(int argc, char const *argv[])
{
    long time=2_hrs;

    cout<<"time = "<<time<<endl;  //represented as ms
    
    return 0;
}