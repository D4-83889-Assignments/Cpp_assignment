#include <iostream>
using namespace std;

struct Date
{

    int day;
    int month;
    int year;

    void initDate()
    {
        day = 1;
        month = 1;
        year = 1901;
    }

    void printDateOnConsole()
    {
        cout << "Day : " << day << "   Month: " << month << "   Year: " << year << endl;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter day" << endl;
        cin >> day;
        cout << "Enter Month" << endl;
        cin >> month;
        cout << "Enter Year" << endl;
        cin >> year;
        cout << "Date has been entered in the system!!" << endl;
    }
    bool isLeapYear()
    {
        // Leap year is divisible by 4, not divisible by 100 unless divisible by 400
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        return false;
    }
};

int menu()
{
    int option;
    cout << "0:For exit" << endl;
    cout << "1:For giving your own date" << endl;
    cout << "2:Printing the date" << endl;
    cout << "3: Check if year is leap or not" << endl;
    cout << "Enter Your choice" << endl;
    cin >> option;
    return option;
}
int main()
{
    struct Date d;
    int choice;
    d.initDate();
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
       

        case 1:
            d.acceptDateFromConsole();
            break;

        case 2:
            d.printDateOnConsole();
            break;
        case 3:
           cout<<(d.isLeapYear()?"Leap Year":"Not a Leap Year")<<endl;
            break;

        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }
    cout << "Thank you" << endl;
    return 0;
}