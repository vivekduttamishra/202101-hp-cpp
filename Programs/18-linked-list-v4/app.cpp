#include <stdio.h>
#include <iostream>
#include <exception>
#include <time.h>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;
#include "utils.h" //isPrime



void fillList(LinkedList &list, int count, int fillValue=0){
    for(int i=0;i<count;i++){
        list.add(fillValue);
    }
}

void showList(const LinkedList& list, const char * message){
    cout<<message<<"\t";
    for(int i=0;i<list.size();i++)
        cout<<list[i]<<"\t";

    cout<<endl;
}

int testArithmeticOperators()
{

    LinkedList list1,list2;

    fillList(list1, 10, 5);
    fillList(list2, 10, 20);

    showList(list1,"list1");
    showList(list2,"list2");

    LinkedList list3= list1+list2;
    showList(list3,"list1+list2");

    LinkedList list4=list1*list2;
    showList(list4, "list1*list2");


    LinkedList list5 = list4 * 5;  //multiply each item of the list 5
    showList(list5,"list4 * 5");

    LinkedList list6 = 10 * list4;  //what will happen?



    return 0;

}

void testListOperatos(){
       LinkedList qty;

    cout<< "original list:" << qty <<endl;

    qty.add(10).add(20).add(30).add(40).add(50);

    LinkedList rate;

    rate<< 5 << 100<< 20 << 10 << 100;

    LinkedList price= qty*rate;

    cout<<"Qty\tRate\tPrice"<<endl;
    for(int i=0;i<qty.size();i++)
    {
        cout<< qty[i] << "\t" << rate[i] << "\t"<< price[i]<<endl;

        price[i] -= 20; // price[i] = price[i] - 20
    }


    

    cout<<endl;

    

    //showList(price,"price after discount");

    cout<<"price after discount is "<< price <<endl;

 
}


void testPerformance(){
     LinkedList list;
    
    int max=100000;
    
    
    cout<<"program started. adding "<<max<<" to list...";
    time_t start,end;
    time(&start);
    for(int i=0;i<max;i++){
        list.add(i);
    }
    time(&end);
    cout<<"added  "<<list.size()<<"items in "<<(end-start)<<" s"<<endl;


    unsigned long sum=0;
    cout<<"trying to sum all values...";
    time(&start);
    for(int i=0;i<max;i++)
        sum+=list[i];  //accessing each item

    time(&end);
    cout<<"sum calcualated "<< sum<< "in "<<(end-start)<< "s"<<endl;

}


void testFindStrategy()
{

    LinkedList list;

    list<< 2 << 15 << 5 << 4 << 7 << 11 << 18 << 40;

    cout<<"list.indexOf(5) = "<<list.indexOf(5)<<endl;
    
    cout<<"list.indexOf(50) = "<<list.indexOf(50)<<endl;

     cout<<"list.average() = "<<list.average()<<endl;  //sum all items

    //  cout<<"list.findEvens() = "<<list.findEvens()<<endl;  // LinkedList (2 4 18 40)

    //  cout<<"list.findPrimes() = "<<list.findPrimes()<<endl;  //LinkedList (2, 5, 7, 11)

    cout<<"list.find(isPrime) = "<<list.find(isPrime)<<endl;
    
    auto isOdd= [] (const Data & n) { return n%2!=0 ;};

    

    cout<<"list.find(isOdd) = "<<list.find(isOdd)<<endl;
    
    
    cout<<"list.find([](const int & x){ return x%2==0;}) = "<<list.find([](auto x){ return x%2==0;})<<endl;
    
}

void testIteratorPerformance(){
     LinkedList list;
    
    int max=100000;
    
    
    cout<<"program started. adding "<<max<<" to list...";
    time_t start,end;
    time(&start);
    for(int i=0;i<max;i++){
        list.add(1);
    }
    time(&end);
    cout<<"added  "<<list.size()<<"items in "<<(end-start)<<" s"<<endl;


    unsigned long sum=0;
    cout<<"trying to sum all values...";
    time(&start);
    
    // for(int i=0;i<max;i++)
    //     sum+=list[i];  //accessing each item

   
    for( auto ptr = list.begin(); ptr!= list.end() ;  ++ptr){        
        sum+=*ptr;
    }

    time(&end);
    cout<<"sum calcualated "<< sum << "in "<<(end-start)<< "s"<<endl;

}





int main(){


    testIteratorPerformance();

    LinkedList list;
    list<< 2 << 3 << 5 << 9 << 8;


    LinkedList::SmartPointer ptr= list.begin();    

    while(ptr){
        
        cout<< *ptr <<endl;
        ptr++;

    }

    LinkedList::SmartPointer x=list.begin();
    cout<<"\naccessing all items from 0 to 4"<<endl;
    while(x != list.at(2)){
        cout<< *x <<endl;
        x++;
    }

   
    return 0;
}