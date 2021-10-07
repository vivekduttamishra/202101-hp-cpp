#pragma once
#include <iostream>
#include <exception>
using namespace std;

namespace conceptarchitect::data
{

    class IndexError : public exception
    {
        //fields

        int index;
        //  const char *reason;

    public:
        IndexError(int index, char const *const reason = "Index Error") noexcept

        {
            this->index = index;
            //    this->reason=reason;
        }
        //Methods        

        int getIndex() const { return index; }
    };

}
