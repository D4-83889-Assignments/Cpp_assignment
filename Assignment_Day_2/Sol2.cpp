#include <iostream>
using namespace std;
class ToolBooth
{

private:
    unsigned int totalCars;
    double totalMoney;

public:
    ToolBooth()
    {
        totalCars = 0;
        totalMoney = 0;
    }
    void payingCars()
    {
        totalCars++;
        totalMoney += 0.5;
        cout << "Toll Received" << endl;
    }
    void nonPayingCar()
    {
        totalCars++;
        cout << "Toll not received" << endl;
    }
    void checkStatus()
    {
        cout << "TotalCars: " << totalCars << " TotalMoney: " << totalMoney << endl;
    }
};
int menu()
{
    int option;
    cout << "0. Exit ToolBooth" << endl;
    cout << "1. Paying Car " << endl;
    cout << "2. Non Paying Car" << endl;
    cout << "3. Check Status" << endl;
    cout << "Enter Your Choice" << endl;
    cin >> option;
    return option;
}

int main()
{
    ToolBooth t1;
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            t1.payingCars();
            break;

        case 2:
            t1.nonPayingCar();
            break;

        case 3:
            t1.checkStatus();
            break;
        default:
            cout << "Invalid Option!!!" << endl;
        }
    }
    cout << "TollBooth closed!!" << endl;
    return 0;
}