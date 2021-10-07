#pragma once
#include <iostream>
#include <exception>
using namespace std;
#include "index-error.h"

#define Data int
#define POS_END -1

namespace conceptarchitect::data
{

    class LinkedList
    {
        struct Node
        {
            Node *next;
            Node *previous;
            Data value;
        };

        Node *first;
        Node *last;
        int count;

        Node *locate(int pos) const
        {
            if(pos==POS_END)
                pos=count-1;

            if(pos<0 || pos>=count)
                //throw range_error("invalid index");
                throw IndexError(pos);

            if(pos==count-1)
                return last;

            Node *n = first;
            for (int i = 0; i < pos && n; i++)
                n = n->next;

           
            return n;
        }

        LinkedList(const LinkedList& other)
        {
            //what you write here in private doesn't matter 
            //it can even be blank.
            first=NULL;
            last=NULL;
            count=0;

            addAll(other);
        }

    public:
        LinkedList()
        {
            first = NULL;
            last = NULL;
            count = 0;
        }

       

        void addAll(const LinkedList & other){

            for(Node * p= other.first; p ; p=p->next)
            {
                add(p->value); //create a new node and add the value, update the count
            }

        }

        ~LinkedList()
        {
            clear();
        }

        void clear(){
            Node * n=first;

            while(n){
                Node * d=n;
                n=n->next;
                delete d;
            }

            first=NULL;
            last=NULL;
            count=0;
          
        }

        // add at the end of the list
        void add(Data value)
        {
            Node *newNode = new Node;
            newNode->next = NULL; //this will be the last Node
            newNode->value = value;
            newNode->previous = last;

            if (first == NULL)
            {
                first = newNode;
            }
            else
            {
                last->next = newNode;
            }

            last = newNode;
            count++;
        }

        int size() const
        {

            return count;
        }

        int get(int pos) const
        {
            //i don't care if locate is successful
            //if it is not, I won't get a chance to proce ->value
            return locate(pos)->value;
        }

        void set(int pos, Data newData)
        {
            locate(pos)->value = newData;
        }

        Data remove(int pos=POS_END)
        {

            Node *d = locate(pos);

            //if you reach here locate was a success

            if (d == first)
                first = d->next;
            else
                d->previous->next = d->next;

            if (d==last) //not the last item
                last=d->previous;
            else
                d->next->previous = d->previous;

            Data value = d->value;
            delete d; //must free the memory
            count--;
            return value;
        }
    };

}