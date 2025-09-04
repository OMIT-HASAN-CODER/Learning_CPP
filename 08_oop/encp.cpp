#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    //Method to deposit money
    void deposit() {
        double amount;
        cout << "Enter amount to deposit: " << endl;
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    //Method to withdraw money
    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: " << endl;
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawn amount" << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount myAccount("1229988", 500);
    myAccount.displayAccountDetails();
    myAccount.deposit();
    myAccount.withdraw();
    myAccount.displayAccountDetails();
    return 0;
}