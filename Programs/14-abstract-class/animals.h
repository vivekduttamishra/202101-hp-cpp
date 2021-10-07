#pragma once
#include <iostream>
using namespace std;



class Animal
{
    public:
    //virtual void eat(){ cout<<"I don't know what it eats"<<endl;}
    virtual void eat()=0;
    
   // virtual void move() {cout<<"moves on it's legs"<<endl;}
    virtual void move()=0;

    void die() {cout<<"Oh! it's dead."<<endl;}
};

class Tiger:public Animal{
    int huntingSkill;

    public:
    Tiger(int huntingSkill=5):huntingSkill(huntingSkill){}
    void eat(){ 
        hunt();
        cout<<"Tiger is eating its pray"<<endl;
    }

    void move(){
        cout<<"Tiger moves on ground"<<endl;
    }

    void hunt()
    {
        cout<<"Tiger hunts down it's pray with skill "<<huntingSkill<<endl;
    }

};

class Fish: public Animal{

     public:
    void eat(){         
        cout<<"fish eats in river"<<endl;
    }

    void move(){ 
        cout<<"fish swims"<<endl;
    }
};
