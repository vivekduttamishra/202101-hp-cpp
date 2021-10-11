#pragma once
#include <iostream>
#include <exception>
using namespace std;
#include "index-error.h"
//#include "utils.h"

//#define Data int
#define POS_END -1

namespace conceptarchitect::data
{

    //typedef bool (*Matcher)(const Data &);

    // template<typename Data>
    // struct Node
    // {
    //     Node *next;
    //     Node *previous;
    //     Data value;
    // };

    template <typename Data>
    class LinkedList
    {
        struct Node
        {
            Node *next;
            Node *previous;
            Data value;  //initalized using copy constructor

            Node(Data value,  Node *previous=nullptr,Node *next=nullptr)   
                : value(value)  //set during initalization using copy constructor             
            {
                //this->value=value;  //value is reassigned using operator=
                this->next=next;
                this->previous=previous;

            }
        };

        // Node<Data> *first;
        // Node<Data> *last;

        Node * first ;
        Node * last;

        int count;

        Node *locate(int pos) const 
        {
            if (pos == POS_END)
                pos = count - 1;

            if (pos < 0 || pos >= count)
                //throw range_error("invalid index");
                throw IndexError(pos);

            if (pos == count - 1)
                return last;

            Node *n = first;
            for (int i = 0; i < pos && n; i++)
                n = n->next;

            return n;
        }

    public:
        LinkedList()
        {
            first = NULL;
            last = NULL;
            count = 0;
        }

        LinkedList(const LinkedList &other)
        {
            //what you write here in private doesn't matter
            //it can even be blank.
            first = NULL;
            last = NULL;
            count = 0;

            addAll(other);
        }

        void addAll(const LinkedList &other)
        {

            for (Node *p = other.first; p; p = p->next)
            {
                add(p->value); //create a new node and add the value, update the count
            }
        }

        ~LinkedList()
        {
            clear();
        }

        void clear()
        {
            Node *n = first;

            while (n)
            {
                Node *d = n;
                n = n->next;
                delete d;
            }

            first = NULL;
            last = NULL;
            count = 0;
        }

        // add at the end of the list
        LinkedList &add(Data value)
        {
            Node *newNode = new Node(value, last);  //value, previous
            //newNode->next = NULL; //set to nullptr by default
            //newNode->value = value; //set by constructor
            //newNode->previous = last; //set by constructor

            if (!first)
            {
                first = newNode;
            }
            else
            {
                last->next = newNode;
            }

            last = newNode;
            count++;

            return *this;
        }

        LinkedList &operator<<(const Data &data)
        {
            add(data);
            return *this;
        }

        int size() const
        {

            return count;
        }

        Data get(int pos) const
        {
            return (*this)[pos];
        }

        //both get and set
        Data &operator[](int pos) 
        {
            return locate(pos)->value;
        }

        //works specificially for a const list
        const Data  &operator[](const int pos) const 
        {
            return locate(pos)->value;
        }

        void set(int pos, Data newData)
        {
            locate(pos)->value = newData;
        }

        Data remove(int pos = POS_END) 
        {

            Node *d = locate(pos);

            //if you reach here locate was a success

            if (d == first)
                first = d->next;
            else
                d->previous->next = d->next;

            if (d == last) //not the last item
                last = d->previous;
            else
                d->next->previous = d->previous;

            Data value = d->value;
            delete d; //must free the memory
            count--;
            return value;
        }

       // friend ostream &operator<<(ostream &os, const LinkedList<Data> &list);

        int indexOf(const Data &value) const
        {
            int i = 0;
            for (Node *n = first; n; n = n->next)
            {
                if (n->value == value)
                    return i;
                i++;
            }
            return -1;
        }



        class SmartPointer
        {

            Node *ptr; //private

        public:
            SmartPointer(Node *ptr)
            {
                this->ptr = ptr;
            }

            Data &operator*()
            {
                return ptr->value;
            }

            //prefix in nature
            SmartPointer &operator++()
            {
                if (ptr)
                    ptr = ptr->next;

                return *this;
            }

            //postfix increment take one additional argument
            //we never pass this argument
            SmartPointer &operator++(int dummy)
            {
                return ++(*this);
            }

            bool operator==(const SmartPointer &other) const
            {
                return ptr == other.ptr;
            }

            bool operator!=(const SmartPointer &other) const
            {
                return ptr != other.ptr;
            }

            operator bool()
            {
                return ptr != NULL;
            }
        };

        SmartPointer begin()
        {
            return SmartPointer(first);
        }

        SmartPointer end()
        {
            return SmartPointer(NULL);
        }

        SmartPointer at(int pos)
        {
            Node *n = locate(pos);

            return SmartPointer(n);
        }
    };


    template<typename T>
    ostream &operator<<(ostream &os, LinkedList<T> &list)
    {

        if (list.size() == 0)
            return os << "(empty)";

        os << "(\t";
        // for(int i=0;i<list.size();i++)
        //     os<< list[i] <<"\t";  //CAUSES A PERFORMANCE ISSUE BECAUSE OF LINEAR NAURE
        //LinkedList<T>::SmartPointer p= list.begin();

        auto p=list.begin(); // C++ 11 feature

        while(p){
            os<< * p <<"\t";
            p++;
        }

        // for (LinkedList<T>::Node *n = list.first; n; n = n->next)
        //     os << n->value << "\t";

        os << ")";
        return os;
    }  

}