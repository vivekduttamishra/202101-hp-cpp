#include <stdio.h>
#include <iostream>
#include <exception>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;


void checkMemoryAllocation(){

    int i=0;
    
    while(true){

        i++;
        LinkedList list;
        for(int x=0;x<10000;x++)
            list.add(x);

        if(i%100==0)
            cout<<" + ";

        //destructor of the list will be called here
    }


}

void fillList(LinkedList &list, int count, int fillValue=0){
    for(int i=0;i<count;i++){
        list.add(fillValue);
    }
}

//void showList(LinkedList list, const char * message){

void showList(const LinkedList& list, const char * message){
    cout<<message<<"\t";
    for(int i=0;i<list.size();i++)
        cout<<list.get(i)<<"\t";

    cout<<endl;
}

void testListFillAndShow(){

    cout<<"fill and show"<<endl;
    LinkedList list1;

    fillList(list1, 10 , 1);

    showList(list1," list1");

    showList(list1,"list1");
    cout<<endl<<endl;
}

void testCopy(){

    cout<<"test copy"<<endl;
    LinkedList list1;

    fillList(list1, 10 , 1);
    
    //LinkedList list2=list1;  //copy constructor called

    //if you need to copy use addAll

    LinkedList list2;

    list2.addAll(list1); //an explict deep copy algorithm.


    list2.set(5,100);    //modify the copied list

    showList(list2,"list2 modified");  //show modified list2

    showList(list1,"list1 unmodified"); //show unmodfied list1

    cout<<endl<<endl;

}


int main()
{

   //

   testListFillAndShow();

   testCopy();

   checkMemoryAllocation();

    return 0;
}