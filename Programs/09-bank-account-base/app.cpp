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
    BankAccount a1(1,"vivek","password",amount,interestRate);

    double expectedBalanceAfterInterestCredit= amount*(1+ interestRate/1200);

    a1.creditInterest();

    if(a1.getBalance()==expectedBalanceAfterInterestCredit)
        cout<<"PASSED:\tInterest Credit Test"<<endl;
    else
        cout<<"FAILED:\tInterest Credit Test"<<endl;


}


void withdrawTests(){

    string password="p@ss";
    BankAccount a1= BankAccount(1,"vivek",password,50000,12);
    

    testWithdraw(a1, -2000, password, ERROR_INVALID_DENOMINATION, "Can't withdraw Negative Amount" );

    testWithdraw(a1, a1.getBalance()+1, password, ERROR_INSUFFCIENT_BALANCE, "Can't withdraw more than balance");

    testWithdraw(a1, a1.getBalance()-1, "wrong-password", ERROR_INVALID_PASSWORD,"Can't withdraw with wrong password");

    testWithdraw(a1, 1, password, TRANSACTION_SUCCESS, "Happy Case");


    
}

void testAccountCreation(){
    BankAccount a1(1,"Vivek","p@ss",50000,12);

    BankAccount a2(1,"Sanjay","p@ss",50000,14);

    a1.show();

    a2.show();
    
}


int main(){
    
    testAccountCreation();
    creditInterestTests();
    withdrawTests();
    
    return 0;
}