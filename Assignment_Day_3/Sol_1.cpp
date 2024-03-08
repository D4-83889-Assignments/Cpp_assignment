#include <iostream>
using namespace std;

class BankAccount
{
    const int bankAccNo;
    static int bankAccGen;
    string name;
    int bankBalance;

public:
    BankAccount() : bankAccNo(++bankAccGen)
    {
    }
    void createAccount()
    {
        cout << "Enter Name: " << endl;
        cin >> name;
        cout << "Enter Deposit Amount" << endl;
        cin >> bankBalance;
    }
    void deposit()
    {
        int deposit;
        cout << "Enter Amount to deposit" << endl;
        cin >> deposit;
        bankBalance += deposit;
    }
    void withdraw()
    {
        int withdraw;
        cout << "Enter Withdraw Amount" << endl;
        cin >> withdraw;
        bankBalance -= withdraw;
    }

    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << bankAccNo << endl;
        cout << "Bank Balance: " << bankBalance << endl;
    }
};
int BankAccount::bankAccGen = 1000;
int menu()
{
    int choice;
    cout << "0.EXIT." << endl;
    cout << "1 CREATE ACCOUNT." << endl;
    cout << "2.DEPOSIT" << endl;
    cout << "3.WITHDRAW." << endl;
    cout << "4.Display Account Details" << endl;
    cout << "ENTER YOUR CHOICE.." << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    BankAccount b;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:

            b.createAccount();
            break;
        case 2:
            b.deposit();
            break;
        case 3:
            b.withdraw();
            break;
        case 4:
            b.displayDetails();
            break;
        default:
            cout << "Invalid choice" << endl;

            break;
        }
    }
    return 0;
}