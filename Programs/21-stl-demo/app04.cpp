#include <iostream>
#include <vector>   //all stl component are in std namespace
#include <algorithm>


using namespace std; 


template<class T>
void showList(const T &items,string header=""){
    cout<<header<<" : ";
     for(auto item:items)
        cout<<item<<"\t";

    cout<<endl;

}

int main(){

    int values[]={2,3,9,11,18,17,24,5,8,17,22,2};

    vector<int> numbers;

    for(int value: values)
        numbers.push_back(value);
    
   
    showList(numbers,"original vector");

    sort(numbers.begin(), numbers.end());

    showList(numbers, "sorted vector");
    

    string names []={"INDIA","USA","UK","FRANCE","JAPAN","AUSTRALIA","BURMA"};

    showList(names, "Original Order of Names");

    sort(names,names+5);  //Australia and Burma will not be sorted

    showList(names, "After shorting first five items");

   
    return 0;
}