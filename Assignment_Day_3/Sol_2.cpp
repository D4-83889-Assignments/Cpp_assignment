#include <iostream>
using namespace std;
class Time
{
private:
    int hrs;
    int min;
    int sec;

public:
    Time()
    {
        this->hrs = 1;
        this->min = 1;
        this->sec = 1;
    }
    int getHour()
    {
        return hrs;
    }
    int getMin()
    {
        return min;
    }
    int getSec()
    {
        return sec;
    }
    void printTime()
    {
        cout << "Hours: " << hrs << " Minutes: " << min << " Seconds: " << sec << endl;
    }
    void setHrs(int hrs)
    {
        this->hrs = hrs;
    }
    void setMin(int min)
    {
        this->min = min;
    }

    void setSec(int sec)
    {
        this->sec = sec;
    }
};
int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Get Time" << endl;
    cout << "2.Get Hours" << endl;
    cout << "3.Get Minutes" << endl;
    cout << "4.Set Seconds" << endl;
    cout << "5.Set Hour" << endl;
    cout << "6.Set Minutes" << endl;
    cout << "7.Set Seconds" << endl;
    cout << "Enter Your Coice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    Time t;
    int sec;
    int min;
    int hrs;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            t.printTime();
            break;
        case 2:
            cout<<t.getHour()<<endl;
            break;
        case 3:
            cout<<t.getMin()<<endl;
            break;
        case 4:
            cout<<t.getSec()<<endl;
            break;
        case 5:
            cout << "Enter hours" << endl;
            cin >> hrs;
            t.setHrs(hrs);
            break;
        case 6:
            cout << "Enter minutes" << endl;
            cin >> min;
            t.setMin(min);
            break;
        case 7:
            cout << "Enter seconds" << endl;
            cin >> sec;
            t.setSec(sec);
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }
    cout << "ThankYou" << endl;
}