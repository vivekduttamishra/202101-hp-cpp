#include <iostream>
#include <vector>   //all stl component are in std namespace
#include <algorithm>


using namespace std; 


int main(){

    vector<string> countries;  //dynamic array

    

    countries.push_back("India");
    countries.push_back("USA");
    countries.push_back("France");
    countries.push_back("Japan");

    string s;

    cout<<"total size :"<<countries.size()<<endl;

    cout<<"country list using []"<<endl;
    for(int i=0;i<countries.size();i++){

        cout<<i<<"\t"<<countries[i]<<endl;  //overloaded []
        countries[i]+="_visited";
    }


    cout<<"accessing the details using iterators"<<endl;

    for(auto ptr= countries.begin();ptr!= countries.end(); ptr++){
        cout<<  ">\t"  << *ptr << endl;
        *ptr+="_again";
    }


    cout<<"using c++ 11 for-each loop syntax\t"<<endl;
    for(auto country : countries){
        cout<<">>\t"<< country<<endl;
    }

    cout<<"using stl foreach function"<<endl;

    for_each(countries.begin(), countries.end(), [](auto country){cout<<"*\t"<<country<<endl;});


    return 0;
}