#include <iostream>
#include "bank-account.h"


void testWithdraw(BankAccount &account, double amount, string password, int expectedResult, string testName){

    int result= account.withdraw(amount,password);

    if(result==expectedResult)
        cout<<"PASSED:\t"<<testName<<endl;
    else
        cout<<"FAILED:\t"<<testName<<endl
            <<"\tExpected:"<<expectedResult
            <<"\tFound:"<<result<<endl;        
        


}



void creditInterestTests(){
    double amount=50000;
    double interestRate=12;
    
    //BankAccount::interestRate=interestRate;
    BankAccount::setInterestRate(interestRate);

    BankAccount a1("vivek","password",amount);

    double expectedBalanceAfterInterestCredit= amount*(1+ interestRate/1200);

    a1.creditInterest();

    if(a1.getBalance()==expectedBalanceAfterInterestCredit)
        cout<<"PASSED:\tInterest Credit Test"<<endl;
    else
        cout<<"FAILED:\tInterest Credit Test"<<endl;


}


void withdrawTests(){

    string password="p@ss";
    BankAccount a1= BankAccount("vivek",password,50000);
    

    testWithdraw(a1, -2000, password, ERROR_INVALID_DENOMINATION, "Can't withdraw Negative Amount" );

    testWithdraw(a1, a1.getBalance()+1, password, ERROR_INSUFFCIENT_BALANCE, "Can't withdraw more than balance");

    testWithdraw(a1, a1.getBalance()-1, "wrong-password", ERROR_INVALID_PASSWORD,"Can't withdraw with wrong password");

    testWithdraw(a1, 1, password, TRANSACTION_SUCCESS, "Happy Case");


    
}

void testInterestRate(){

    cout<<"sizeof(BankAccount) = "<<sizeof(BankAccount)<<endl;    
    cout<<"BankAccount::interestRate = "<<BankAccount::getInterestRate()<<endl;
    
    BankAccount a1("Vivek","p@ss",50000);
    BankAccount a2("Sanjay","p@ss",50000);

    //setting interest rate for BankAccount changes it for everyone
    //BankAccount::interestRate=15; //private

    BankAccount::setInterestRate(13);
    

    cout<<"After Changing Rate using BankAccount::interestRate =15"<<endl;
    cout<<"BankAccount::interestRate = "<<BankAccount::getInterestRate()<<endl;
    cout<<"a1.interestRate = "<<a1.getInterestRate()<<endl;
    cout<<"a2.interestRate = "<<a2.getInterestRate()<<endl<<endl;

    a1.setInterestRate(18);

    cout<<"After Changing Rate using a1.interestRate=18"<<endl;
    cout<<"BankAccount::interestRate = "<<BankAccount::getInterestRate()<<endl;
    cout<<"a1.interestRate = "<<a1.getInterestRate()<<endl;
    cout<<"a2.interestRate = "<<a2.getInterestRate()<<endl<<endl;

    
    
    
    
}

void testAccountNumberGeneration(){

    BankAccount a1("Vivek","p@ss",50000);
    BankAccount a2("Sanjay","great",25000);

    cout<<a1.getAccountNumber()<<endl
        <<a2.getAccountNumber()<<endl;

}

int main(){

    testAccountNumberGeneration();    
    testInterestRate();
   // creditInterestTests();
    //withdrawTests();
    
    return 0;
}