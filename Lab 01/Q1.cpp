#include<iostream>
using namespace std;

class BankAccount{
double balance;
public:
BankAccount(){
    balance = 0.0;
}
double getBalance(){
    return balance;
}
BankAccount(double bal){
    if(bal >= 0){
        balance = bal;
    }
    else{
        balance = 0.0;
        cout << "Insufficient balance entry"<<endl;
    }
}
BankAccount(const BankAccount &a3){
    this->balance = a3.balance;
}
double Deduct(double amount){
    balance -= amount;
}};
int main(){
    BankAccount account1;
    cout <<"Account 1: "<< account1.getBalance() << endl;
    BankAccount account2(1000.0);
    cout <<"Account 2: "<< account2.getBalance() << endl;
    BankAccount account3(account2);
    account3.Deduct(200.0);
    cout <<"Account 3: "<< account3.getBalance() << endl;
    cout <<"Account 2: "<< account2.getBalance() << endl;

 return 0;   
}
