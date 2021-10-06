#pragma once
#include <iostream>
using namespace std;

class Bank
{
    //fields
    //array of accounts
    double interestRate;
    int accountCount;
    
    public:
        Bank(){
            //initialize fields
        }
        //Methods
        int openAccount(string name, string password, double amount);
        bool closeAccount(int accountNumber, string password); //only if account has positive balance
        bool deposit(int accountNumber, double amount){

            //1. find the account based on acccount number
            //2. call deposit of the account number
        }

        //also implement withdraw

        void creditInterest(); //credit interest to every account
        void transfer(int fromAccount, double amount, string password, int toAccount);
};