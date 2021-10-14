#pragma once
#include <iostream>
using namespace std;

template<typename T>
class SmartPointer{

    T * ptr;

    public:
    SmartPointer(T * ptr):ptr(ptr){}
    ~SmartPointer(){ delete ptr;}

    T& operator*(){
        return *ptr;
    }

    T& operator->(){
        return *ptr;
    }



};


template<typename Lock>
struct SafeLock
{
    Lock *lock;

    SafeLock(Lock &lock){
        this->lock=&lock;
        this->lock->lock();
    }

    SafeLock(Lock* lock){
        this->lock=lock;
        this->lock->lock();
    }

    ~SafeLock(){ 
        this->lock->unlock();
    }
};