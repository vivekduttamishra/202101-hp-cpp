#pragma once
#include <iostream>
using namespace std;

template <typename King, typename Queen>
class Couple
{
    King king;
    Queen queen;
    public:
    Couple(King king, Queen queen)
    {
        this->king=king;
        this->queen=queen;
    }

    King getKing() const { return this->king; }
    Queen getQueen() const { return this->queen; }
    void setKing(const King king) { this->king=king;}
    void setQueen(const Queen queen) { this->queen=queen;}

    
   // friend inline ostream & operator<<<King,Queen>(ostream & os, const Couple<King,Queen> & couple)

};

template <typename First,typename Second>
inline ostream & operator<<(ostream & os, const Couple<First,Second> & couple)
{
    return os<<"Couple( "<<couple.getKing()<<","<<couple.getQueen()<<")";
}