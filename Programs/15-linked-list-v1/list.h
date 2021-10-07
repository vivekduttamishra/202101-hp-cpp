#pragma once
#include <iostream>
using namespace std;

#define Data int

namespace conceptarchitect::data{

    struct Node
    {
        Node * next;
        Node * previous;
        Data value;
    };


    class LinkedList
    {
        Node * first;

        public:
        LinkedList(){
            first=NULL;
        }

        // add at the end of the list
        void add(Data value) 
        {
            Node * newNode= new Node;
            newNode->next=NULL;  //this will be the last Node
            newNode->value=value;

            if(first==NULL){
                //list is Empty
                first=newNode;
                newNode->previous=NULL; //this is the only node currently present
            } 
            else
            {
                //adding to the end of non empty list
                //move to the last node
                Node *last=first;

                while(last->next)
                    last=last->next;

                newNode->previous=last;
                last->next=newNode;
            }

        }
    
    
        int size() const { 

            int count=0;
            Node * node=first;
            while(node){
                count++;
                node=node->next;
            }

            return count;

        }


        int get(int pos) const { 

            Node * n = first;

            for(int i=0; i<pos && n;i++)
                n=n->next;

            if(n)
                return n->value;
            else
                throw "invalid index";
        
        }


        void set(int pos, Data newData)  { 

            Node * n = first;

            for(int i=0; i<pos && n;i++)
                n=n->next;

            if(n)
                n->value=newData;
            else
                throw "invalid index";
        
        }


        Data remove(int pos)  { 

            Node * n = first;

            for(int i=0; i<pos && n;i++)
                n=n->next;

            if(n)
            {
                Node * d= n;

                if(d==first)
                    first=d->next;
                else
                    d->previous->next=d->next;

                if(d->next) //not the last item
                    d->next->previous=d->previous;

                Data value=d->value;
                delete d; //must free the memory
                return value;
            }                
            else
                throw "invalid index";
        
        }





    };


}