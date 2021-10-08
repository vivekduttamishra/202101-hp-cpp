#include <stdio.h>
#include <iostream>
#include <exception>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;



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


int main()
{

    LinkedList qty;

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

    showList(price,"price after discount");

    return 0;
}