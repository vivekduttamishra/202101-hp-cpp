#include <boost/format.hpp>
#include <iostream>

using namespace std;

int main()
{
  std::cout << boost::format{"%1%.%2%.%3%"} % 12 % 5 % 2014 << '\n';

  int a=20;
  int b=30;

  auto output= boost::format("sum of %d and %d is %d") % a % b % (a+b); 

  cout<<output<<endl;

}