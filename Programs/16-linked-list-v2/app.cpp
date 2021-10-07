#include <stdio.h>
#include <iostream>
#include <exception>
#include "list.h"
using namespace std;
using namespace conceptarchitect::data;

void showItems(string message, LinkedList list, int count = -1)
{

    if (count == -1)
        count = list.size();

    cout << message << "\t";

    for (int i = 0; i < count; i++)
        cout << list.get(i) << "\t";

    cout << endl;
}

void testLoopInTry(LinkedList list)
{
    try
    {
        int counts[] = {-1, 10, 2};

        for (int i = 0; i < 3; i++)
        {
            cout << "showing count :" << counts[i] << "\t";
            showItems("list", list, counts[i]);
        }
    }
    catch (const exception & error)
    {
        cout << "ERROR: " << error.what() << endl;
    }
}

void testTryInLoop(LinkedList list)
{

    int counts[] = {-1, 10, 2};

    for (int i = 0; i < 3; i++)
    {
        try
        {
            cout << "showing count :" << counts[i] << "\t";
            showItems("list", list, counts[i]);
        }
        catch (const IndexError & error)
        {
            cout << "ERROR: Invalid Index "  << error.getIndex()<<endl;
        }
    }
}

void testSet()
{
    LinkedList list;

    for(int i=0;i<10;i++)
        list.add(0);

    for(int i=0;i<list.size();i++)
        list.set(i, i*100);

    cout<<"testing set/get\t";
    for(int i=0;i<list.size();i++)
        cout<< list.get(i)<<"\t";
    
    cout<<endl;
}


void testRemove()
{
    LinkedList list;

    for(int i=0;i<10;i++)
        list.add(i);


    cout<<"removing pos 8:"<< list.remove(8)<<endl; //remove 8th item -->8
    cout<<"removing pos 4:"<<list.remove(4)<<endl;  //removing 4th item -->4
    cout<<"removing pos 4:"<<list.remove(4)<<endl;  //removing 4th item -->5 (after 4 is deleted)


    cout<<"testing set/get\t";
    for(int i=0;i<list.size();i++)
        cout<< list.get(i)<<"\t";
    
    cout<<endl;
}

int main()
{

    LinkedList list;

    list.add(1);
    list.add(10);
    list.add(50);

    cout<<"testing loop in try"<<endl;
    testLoopInTry(list);

    cout<<endl<<endl<<"testing tryInLoop"<<endl;
    testTryInLoop(list);

    testSet();

    testRemove();

    cout << "normal program termination." << endl;

    return 0;
}