#pragma once
#include <iostream>
#include <exception>
using namespace std;

namespace conceptarchitect::data
{

    class Exception : public exception
    {
        const char * reason;
        public:
        Exception(const char* reason)
        {
            this->reason=reason;
        }

        const char * what() const throw()  //I don't throw an exception
        {
            return reason;
        }

    };

    
    class IndexError : public Exception
    {
        //fields

        int index;
      

    public:
        IndexError(int index, char const *const reason = "Index Error") 
            : Exception(reason)
        {
            this->index = index;
           
        }
        int getIndex() const { return index; }
    };

    class CompatibilityError : public Exception{
        public:
        CompatibilityError(const char * reason="Compatibility Error"): Exception(reason){}
    };
    
}
