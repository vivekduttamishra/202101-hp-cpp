#pragma once
#include <iostream>
#include <string>
using namespace std;

#define TRANSACTION_SUCCESS 0
#define ERROR_INVALID_PASSWORD -1
#define ERROR_INSUFFCIENT_BALANCE -2
#define ERROR_INVALID_DENOMINATION -3

class BankAccount
{
    //fields
    int accountNumber;
    string name; 
    string password;
    double balance;
    static double interestRate; //memory not allocated here
    static int accountCount; //UPDATE#2 add a BankAccount level counter
    

    void setPassword(string newPassword)
    {
        //TODO: complete it as an assignment

        //step 1: validate password conforms to the security policy in terms of length, complexity and allowed char combination
        //step 2: encrypt (salt) the password
        this->password = newPassword;
    }

public:


    static double getInterestRate()  { return interestRate; }
    static int setInterestRate(double newInterestRate)
    {
        double delta = interestRate / 10; //10% of current value
        double min = interestRate - delta;
        double max = interestRate + delta;

        if (newInterestRate >= min && newInterestRate <= max )
        {
            interestRate = newInterestRate;
            return 1; //success
        }
        else
            return 0; //failure
    }

 
    

    //UPDATE#1  Interest Rate Removed from constructor parameter
    //UPDATE#2  Remove accountNumber as a prameter
    BankAccount(string name, string password, double balance)
    {
        //initialize fields
        //this->accountNumber = accountNumber; //UPDATE#2 remove user defined value

        this->accountNumber = ++ accountCount;  //UPDATE#2 auto generate account number
        this->name = name;
        //this->password = passwords;
        setPassword(password);
        this->balance = balance;
        //this->interestRate = interestRate;  //UPDATE#1  interest rate not used in the constructor
    }
    //Methods
    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            return false;
        }
        //happy case
        balance += amount;

        return true;
    }

    /* 
            returns error code just like main
            0 --> no error
            other values to indicate success or failure
        */
    int withdraw(double amount, string password)
    {

        if (amount <= 0)
            return ERROR_INVALID_DENOMINATION;

        //if(this->password!=password)
        if (!authenticate(password))
            return ERROR_INVALID_PASSWORD;
        //return false; //withdraw failed

        if (balance < amount)
        {
            //  cout<<"insuffict balance"<<endl; //--> shouldn't display a message from withdraw. violates responisibility
            //what should I do?
            //Return a value which other component (like ATM) can use to display or dispense cash
            //return false;

            return ERROR_INSUFFCIENT_BALANCE;
        }

        //happy case
        balance - amount;
        //return true;

        return TRANSACTION_SUCCESS;
    }

    void creditInterest()
    {
        balance += (balance * interestRate) / 1200;
    }

    //Should there be a show function is business layer? Ideally NO.
    void show() const
    {
        cout << "Account Number:" << accountNumber << endl
             << "Name:" << name << endl
             //<<"password:"<<password<<endl   //---> not displayed due to security issues
             << "Balance:" << balance << endl
             << "Interest Rate:" << interestRate << endl<<endl;
    }

    //Accessors of fields
    int getAccountNumber() const { return accountNumber; }
    //no setAccountNumber as account number is imutable
   string getName() const { return name; }
    bool setName(string name)
    {
        //find the last word in both names and set new name if the last name matches
        //TODO:
        return false;
    }

    double getBalance() const { return balance; }
    //no setBalance(). you can't set balance absolutely. only via transactions like deposit, withdraw etc

    //no getPassword()   //I don't want any one to see the password
    //no setPassword()  // can't simply set a new password to replace the old one.

    //what should be the right way to handle the password?

    bool changePassword(const string oldPassword, const string newPassword)
    {
        //if(password == oldPassword){

        if (authenticate(oldPassword))
        {

            setPassword(newPassword);
            return true;
        }
        else
            return false;
    }

    bool authenticate(string challengePassword) const
    {

        //step 1: encrypt the challenge password and compare the two in encrypted format
        return password == challengePassword;
    }
};