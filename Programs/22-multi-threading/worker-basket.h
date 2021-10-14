#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include "smartobj.h"
using namespace std;


namespace workerapi
{

    namespace v1
    {

        // represents a resource
        class Basket
        {
        public:
            long items = 0;

        public:
            void addItem()
            {

                int i = items;

                i++;

                items = i;
            }
        };

        struct Worker
        {
            Basket *basket;
            long itemsToAdd;
            thread *_thread;

            Worker(Basket *basket, long itemsToAdd)
            {
                this->basket = basket;
                this->itemsToAdd = itemsToAdd;
            }

            void start()
            {
                _thread = new thread([this]()
                                     { work(); });
            }

            void wait()
            {
                _thread->join();
            }

            void work()
            {

                for (int i = 0; i < itemsToAdd; i++)
                {
                    basket->addItem();
                }
            }
        };

    }

    namespace v2
    {

        // represents a resource
        class Basket
        {
        public:
            long items = 0;
            mutex lock; //basket has a lock now.

        public:
            void addItem()
            {

                lock.lock();
                
                int i = items;

                i++;

                items = i;
                
                lock.unlock();
            }
        };

        struct Worker
        {
            Basket *basket;
            long itemsToAdd;
            thread *_thread;

            Worker(Basket *basket, long itemsToAdd)
            {
                this->basket = basket;
                this->itemsToAdd = itemsToAdd;
            }

            void start()
            {
                
                _thread = new thread([this]()
                                     { work(); });
            }

            void wait()
            {
                _thread->join();
            }

            void work()
            {

                for (int i = 0; i < itemsToAdd; i++)
                {
                    basket->addItem();
                }
            }
        };

    }


    inline namespace v3
    {

        // represents a resource
        class Basket
        {
        public:
            long items = 0;
            mutex lock; //basket has a lock now.

        
            void addItem()
            {
                int i = items;

                i++;

                items = i;
            }
        };

        struct Worker
        {
            Basket *basket;
            long itemsToAdd;
            thread *_thread;

            Worker(Basket *basket, long itemsToAdd)
            {
                this->basket = basket;
                this->itemsToAdd = itemsToAdd;
            }

            void start()
            {
                
                _thread = new thread([this]()
                                     { work(); });
            }

            void wait()
            {
                _thread->join();
            }

            void work()
            {

                for (int i = 0; i < itemsToAdd; i++)
                {
                    //SafeLock<mutex> sl {basket->lock};

                    lock_guard<mutex> guard{basket->lock};

                    basket->addItem();
                    //basket->lock.unlock();
                }
            }
        };

    }


}
