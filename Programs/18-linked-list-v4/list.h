#pragma once
#include <iostream>
#include <exception>
using namespace std;
#include "index-error.h"
//#include "utils.h"

#define Data int
#define POS_END -1

namespace conceptarchitect::data
{

    typedef bool (*Matcher) (const Data &);

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

        Node *locate(int pos) const throw(IndexError) //I may throw IndexError
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

        int get(int pos) const throw(IndexError)
        {
            return (*this)[pos];
        }

        //both get and set
        int &operator[](int pos) throw(IndexError)
        {
            return locate(pos)->value;
        }

        //works specificially for a const list
        const int &operator[](const int pos) const throw(IndexError)
        {
            return locate(pos)->value;
        }

        void set(int pos, Data newData)
        {
            locate(pos)->value = newData;
        }

        Data remove(int pos = POS_END) throw(IndexError)
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

        //operator overloading

        // LinkedList list3 = list1 + list2

        LinkedList operator+(const LinkedList &second) const
        {

            if (size() != second.size())
                throw CompatibilityError("The Two list must be of same size");

            LinkedList result;

            int i = 0;
            Node *o1 = first;
            Node *o2 = second.first;

            for (int i = 0; i < size(); i++)
            {

                result.add(o1->value + o2->value);
                o1 = o1->next;
                o2 = o2->next;
            }

            return result;
        }

        LinkedList operator*(const int value) const
        {

            LinkedList result;

            for (Node *n = first; n; n = n->next)
                result.add(n->value * value);

            return result;
        }

        friend ostream &operator<<(ostream &os, const LinkedList &list);

        //More functionalities

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

        double average() const
        {
            double result = 0;

            for (Node *n = first; n; n = n->next)
            {
                result += n->value;
            }

            return result / size();
        }

        // LinkedList findEvens() const
        // {
        //     LinkedList  result ;

        //     for (Node *n = first; n; n = n->next)
        //     {
        //         if(n->value%2==0)
        //             result << n->value;
        //     }
        //     return result;
        // }

        // LinkedList findPrimes() const
        // {
        //     LinkedList  result ;

        //     for (Node *n = first; n; n = n->next)
        //     {
        //         if(isPrime(n->value))
        //             result << n->value;
        //     }
        //     return result;
        // }


        LinkedList find(Matcher match)
        {
            LinkedList result;

            for(Node * n=first; n; n=n->next)
            {
                if(match(n->value))
                    result << n->value;
            }

            return result;
        }
    
    
        class SmartPointer{

            Node * ptr; //private
            public:
            SmartPointer(Node * ptr){
                this->ptr=ptr;
            }

            Data & operator *(){
                return ptr->value;
            }

            //prefix in nature
            SmartPointer & operator++(){
                if(ptr)
                    ptr=ptr->next;

                return *this;
            }

            //postfix increment take one additional argument
            //we never pass this argument             
            SmartPointer & operator++(int dummy){
                return ++(*this);
            }

            bool operator==(const SmartPointer &other) const{ 
                return ptr==other.ptr;
            }

            bool operator!=(const SmartPointer &other) const{
                return ptr!=other.ptr;
            }

            operator bool(){
                return ptr!=NULL;
            }

        };
    

        SmartPointer begin(){
            return SmartPointer(first);
        }

        SmartPointer end(){
            return SmartPointer(NULL);
        }

        SmartPointer at(int pos){
            Node * n= locate(pos);

            return SmartPointer(n);

        }
   
    };

    ostream &operator<<(ostream &os, const LinkedList &list)
    {

        if (list.size() == 0)
            return os << "(empty)";

        os << "(\t";
        // for(int i=0;i<list.size();i++)
        //     os<< list[i] <<"\t";  //CAUSES A PERFORMANCE ISSUE BECAUSE OF LINEAR NAURE

        for (LinkedList::Node *n = list.first; n; n = n->next)
            os << n->value << "\t";

        os << ")";
        return os;
    }

    inline LinkedList operator*(const int value, const LinkedList &list)
    {
        return list * value;
    }

    inline LinkedList operator*(const LinkedList &first, const LinkedList &second)
    {
        LinkedList result;
        int size = first.size() < second.size() ? first.size() : second.size();

        for (int i = 0; i < size; i++)
        {
            result.add(first.get(i) * second.get(i));
        }

        return result;
    }

}