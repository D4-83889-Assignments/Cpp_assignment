#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 12;
        year = 1901;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }

    void display()
    {
        cout << "Date: " << this->day << "/ " << this->month << "/ " << this->year << endl;
    }

    void accept()
    {
        cout << "Enter Day" << endl;
        cin >> day;
        cout << "Enter Month" << endl;
        cin >> month;
        cout << "Enter Year" << endl;
        cin >> year;
    }

    bool isLeap()
    {
        return (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0);
    }
};
class Person // has-a Date
{
    string name;
    string address;
    Date dob;

public:
    Person()
    {
        name = "n/a";
        address = "n/a";
    }

    void displayPerson()
    {
        cout << "Name: " << name << " address: " << address << " DoB: "<<endl;
        dob.display();
    }
    void accept()
    {
        cout << "Enter name of person: " << endl;
        cin >> this->name;
        cout << "Enter date of birth of person: " << endl;
        dob.accept();
        cout << "Enter address of person: " << endl;
        cin >> this->address;
    }
};
class Employee : public Person // is a Person
{
    int id;
    float salary;
    string dept;
    Date doj;

public:
    Employee()
    {
    }
    Employee(int id, float salary, string dept, Date d)
    {
        this->id = id;
        this->salary = salary;
        this->dept = dept;
        this->doj = d;
        accept();
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    float getSalary()
    {
        return this->salary;
    }
    void setDept(string dept)
    {
        this->dept = dept;
    }
    string getDept()
    {
        return dept;
    }
    void getJoiningDate()
    {
        cout<<doj.getDay()<<"/"<<doj.getMonth()<<"/"<<doj.getYear()<<endl;
    }

    void setJoiningDate(Date doj)
    {
        this->doj = doj;
    }

    void display()
    {
        this->displayPerson();
        cout << "Empid: " << id<<endl;
        cout << "Salary: " << salary<<endl;
        cout << "Department: " << dept<<endl;
        cout<<"Date of Joining: ";
        this->doj.display();
    }

    void accept()
    {
        this->doj.accept();
        cout << "Enter salary" << endl;
        cin >> this->salary;
        cout << "Enter id" << endl;
        cin >> this->id;
        cout << "Enter dept" << endl;
        cin >> this->dept;
    }
};

int menu()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. setId" << endl;
    cout << "2. getId" << endl;
    cout << "3. setSalary" << endl;
    cout << "4. getSalary" << endl;
    cout << "5. setDept" << endl;
    cout << "6. getDept" << endl;
    cout << "7. Display" << endl;
    cout << "8. Accept" << endl;
    cout << "9. GetJoiningDate" << endl;
    cout << "10.SetJoingDate" << endl;
    cout << "Enter Your Choice" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Date d;
    Employee e(1234, 10000, "Sales", d);
    // int day;
    // int year;
    // int month;
    // cout<<"Enter day"<<endl;
    // cin>>day;
    // d.setDay(day);
    // cout<<"Enter month"<<endl;
    // cin>>month;
    // d.setMonth(month);
    // cout<<"Enter year"<<endl;
    // cin>>year;
    // d.setYear(year);
    // cout<<d.getDay()<<endl;
    // cout<<d.getMonth()<<endl;
    // cout<<d.getYear()<<endl;
    // d.display();
    // d.accept(15,2,2034);
    // d.display();
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            e.setId(1000);
            break;
        case 2:
            cout << e.getId() << endl;
            break;
        case 3:
            e.setSalary(10000);
            break;
        case 4:
            cout << e.getSalary() << endl;
            break;
        case 5:
            e.setDept("IT");

            break;
        case 6:
            cout << e.getDept() << endl;
            break;
        case 7:
            e.display();
            break;
        case 8:
            e.accept();
            break;
        case 9:
            e.getJoiningDate();
            break;
        case 10:
            e.setJoiningDate(d);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }

    cout << "Thank You!!" << endl;

    return 0;
}