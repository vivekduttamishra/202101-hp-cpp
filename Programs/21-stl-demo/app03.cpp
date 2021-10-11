#include <iostream>
#include <map>   //all stl component are in std namespace

#include <algorithm>


using namespace std; 


int main(){

    map<string,int> countryCodes;

    countryCodes.insert(make_pair("IN",91));
    countryCodes.insert(make_pair("UK",40));
    
    //can also be added using [] notation
    countryCodes["USA"]= 1;   //same as insert

    countryCodes["UK"]=44;  //overwrites the old value for the same key


    for(auto ptr= countryCodes.begin();ptr!= countryCodes.end();ptr++)
        cout<<ptr->first<<"\t"<<ptr->second<<endl;


    // we can find out if given key is present or not.

    string keys[]={"IN","DE","FR","USA"};

    for_each(keys,keys+4, [&countryCodes](auto key){


        cout<< key <<"\t" ;
        
        if(countryCodes.find(key)!=countryCodes.end())
                cout<<countryCodes[key]<<endl;
        else   
                cout<<"not found\n";

    });



   
    return 0;
}