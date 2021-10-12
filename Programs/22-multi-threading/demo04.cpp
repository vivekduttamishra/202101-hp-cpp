#include <iostream>
#include <thread>
using namespace std;

struct CountDown
{
    int max;

    CountDown(int max){this->max=max;}

    void operator()()
    {
        auto id = this_thread::get_id();

        cout << "thread started:" << id << endl;
        
        while (max >= 0)
        {
            cout << "[" << id << "]:" << max << endl;
            max--;
        }
        cout << "thread ends:" << id << endl;
    }
};


int main(int argc, char const *argv[])
{

    auto t1 = thread(CountDown(20));
    auto t2 = thread(CountDown{40});  //C++ 11 initliazer
    

    cout << "[" << this_thread::get_id() << "]:"
         << "waiting for thread to finish" << endl;

    t1.join();
    t2.join();

    cout << "[" << this_thread::get_id() << "]:"
         << "thread finished" << endl;

    return 0;
}