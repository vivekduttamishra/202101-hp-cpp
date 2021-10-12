#pragma once
#include <iostream>
using namespace std;
#include "list.h"


template<typename SmartPointer, typename ActionFunction>
void forEach(SmartPointer start, SmartPointer end, ActionFunction action)
{

    for(auto ptr = start; ptr != end; ptr++)
    {
        action(*ptr);  //do whatever you need to
    }

}


template<typename Container,typename SmartPointer, typename Matcher>
int find(SmartPointer start, SmartPointer end, Matcher matcher,Container & result)
{
   // LinkedList<T> result;

    for(auto ptr = start; ptr != end; ptr++)
    {
        if(matcher(*ptr))
            result.add(*ptr);
    }   

    return result.size();
}

template<typename T>
LinkedList<T> createList(T value){
    return LinkedList<T>{};
}

template<typename Ptr,typename Matcher>
decltype(auto) search(Ptr start, Ptr end, Matcher matcher)
{
    auto result= createList(*start); //create list to hold this type of value

   //LinkedList<decltype(*start)> result= LinkedList<decltype(*start)>();

    for(auto ptr=start;ptr!=end;ptr++)
        if(matcher(*ptr))
            result<< *ptr;
    
    return result;
}



template<typename SmartPointer, typename DoubleFinderFunction>
double average0(SmartPointer first, SmartPointer last, DoubleFinderFunction toDouble)
{
    double count=0;
    double sum=0;

    for(auto ptr=first; ptr != last; ptr++){
        count++;
        sum+= toDouble(*ptr);
    }

    return sum/count;
}

template<typename SmartPointer, typename DoubleFinderFunction>
double average(SmartPointer first, SmartPointer last, DoubleFinderFunction toDouble)
{
    double count=0;
    double sum=0;

   // forEach(first, last, [ & ](auto book){

    forEach(first,last, [&count,&sum, toDouble](auto book){

        sum+=toDouble(book);
        //i can also change first and last
        count++;
    });

    return sum/count;
}