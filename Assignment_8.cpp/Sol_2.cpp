#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class InsufficientFunds
{
private:
    int accid;
    double curr_balance;
    double withdraw_amount;

public:
    InsufficientFunds(int accid, double curr_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->curr_balance = curr_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout << "Sorry,Insufficient Funds available" << endl;
        cout << "Account Id: " << this->accid << endl;
        cout << "Current Balance: " << this->curr_balance << endl;
        cout << "Withdraw Amount: " << this->withdraw_amount << endl;
    }
};

enum AccountType
{
    Saving = 1,
    Current,
    Dmat
};
class Account
{
private:
    double balance;
    int id;
    AccountType type;
    int i;

public:
    Account()
    {
        id = 1;
        balance = 1000;
        type = AccountType::Saving;
    }
    Account(int id, AccountType type)
    {
        this->id = id;
        this->type = type;
        balance = 1000;
    }

    void accept()
    {
        int i;
        double balance;
        cout << "Enter Account id" << endl;
        cin >> i;
        try
        {
            setId(i);
        }
        catch (int e)
        {
            cout << "Id can't be zero or less than zero" << endl;
        }
        cout << "Enter Account Type, 1. for Saving, 2. for Current, 3.Dmat " << endl;
        cin >> i;
        if (i == 1)
        {
            type = AccountType::Saving;
        }
        if (i == 2)
        {
            type = AccountType::Current;
        }
        if (i == 3)
        {
            type = AccountType::Dmat;
        }

        cout << "Enter Start Amount" << endl;
        cin >> balance;
        try
        {
            setBalance(balance);
        }
        catch (int e)
        {
            cout << "Start Amount can't be less than 0" << endl;
        }
    }
    void display()
    {
        cout << "Account Id: " << id << endl;
        cout << "Account Balance: " << balance << endl;
        if (type == 1)
        {
            cout << "Type: Savings" << endl;
        }
        if (type == 2)
        {
            cout << "Type: Current" << endl;
        }
        if (type == 3)
        {
            cout << "Type: Dmat" << endl;
        }
    }

    void setId(int id)
    {
        if (id <= 0)
            throw 1;
        else
        {
            this->id = id;
        }
    }

    void setType(AccountType Type)
    {
        this->type = type;
    }
    int getId()
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }

    void setBalance(double balance)
    {
        if (balance <= 0)
        {
            throw 1;
        }
        else
        {
            this->balance = balance;
        }
    }
    AccountType getType()
    {
        return type;
    }
    void deposit(double amount)
    {
        this->balance += amount;
        cout << "Deposit Successfull!!" << endl;
    }

    void withdraw(double amount)
    {
        if (balance - amount < 100)
        {
            throw InsufficientFunds(id, balance, amount);
        }
        else
        {
            this->balance -= amount;
            cout << "Withdraw Successfull!!" << endl;
        }
    }
};

int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Deposit" << endl;
    cout << "2.Withdraw" << endl;
    cout << "Enter Your Choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int index;
    int choice;
    int amount;
    Account a[3];
    cout << "********************************************************************************" << endl;
    cout << "BANKING SYSTEM" << endl;
    for (int i = 0; i < 3; i++)
    {
        /* code */
        a[i].accept();
    }
    for (int i = 0; i < 3; i++)
    {
        /* code */
        a[i].display();
    }

    // a.deposit(1000);
    // try
    // {
    //     a.withdraw(1950);
    // }
    // catch (InsufficientFunds &e)
    // {
    //     e.display();
    // }
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter index of bank account for deposit" << endl;
            cin >> index;
            if (index < 5)
            {
                cout << "Enter Amount to Deposit" << endl;
                cin >> amount;
                a[index].deposit(amount);
                cout << a[index].getBalance() << endl;
            }
            else
            {
                cout << "Index out of bounds" << endl;
            }
            break;

        case 2:
            cout << "Enter index of bank account for withdraw" << endl;
            cin >> index;
            if (index < 5)
            {
                cout << "Enter Amount to Withdraw" << endl;
                cin >> amount;
                try
                {
                    a[index].withdraw(amount);
                    cout << a[index].getBalance() << endl;
                }
                catch (InsufficientFunds &n)
                {
                    n.display();
                }
            }
            else
            {
                cout << "Index out of bounds" << endl;
            }
            break;

        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }
    cout << "*****************************************************************" << endl;
    cout << "Thanks for using our app" << endl;

    return 0;
}