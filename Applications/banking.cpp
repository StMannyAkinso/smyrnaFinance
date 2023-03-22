// Simple banking application

#include <iostream>
#include <iomanip>
using namespace std;

// Defining the bank account class
class BankAccount
{
private:
    double balance;

public:
    BankAccount()
    {
        balance = 0.0;
    }
    // Account functions
    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds" << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }
};

// main function
int main()
{
    BankAccount myAccount;
    int choice;
    double amount;
    // Display account options
    do
    {
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user functions
        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            cout << "Deposit successful" << endl;
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            cout << "Withdrawal successful" << endl;
            break;
        case 3:
            cout << fixed << setprecision(2);
            cout << "Current balance: $" << myAccount.getBalance() << endl;
            break;
        case 4:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
