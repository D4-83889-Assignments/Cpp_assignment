#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    Date(){
        this->day = 1;
        this->month = 1;
        this->year = 2000;
    }
    void display()
    {
        cout << "Day: " << this->day << endl;
        cout << "Month: " << this->month << endl;
        cout << "Year: " << this->year << endl;
        
    }
    void accept()
    {
        cout << "Enter day" << endl;
        cin >> this->day;
        cout << "Enter month" << endl;
        cin >> this->month;
        cout << "Enter year" << endl;
        cin >> this->year;
    }
};
class Person
{
private:
    Date dob;
    string name;
    string address;

public:
    Person()
    {
        name = "N/A";
        address = "N/A";
    }

    void display()
    {
        cout << "Name: " << this->name << endl;
        cout << "Address: " << this->address << endl;
        cout << "DOB: " << this->address << endl;
        dob.display();
    }
    void accept()
    {
        cout << "Enter name: " << endl;
        cin >> this->name;
        cout << "Enter address: " << endl;
        cin >> this->address;
        cout << "Enter Dob: " << endl;
        this->dob.accept();
    }
};
class Employee : public Person //inheritance
{
private:
    Date doj;//Association //Composition //Necessary data field //Necesary dependancy
    string dept;
    int id;
    int salary;

public:

    void acceptEmployee()
    {
        accept();
        cout<<"Enter date of joining"<<endl;
        doj.accept();
        cout << "Enter dept" << endl;
        cin >> this->dept;
        cout << "Enter salary" << endl;
        cin >> this->salary;
        cout << "Enter id" << endl;
        cin >> this->id;
    }
    void displayEmployee()
    {
        cout << "Basic Details: " << endl;
        display();
        cout << "Date of joining: " << endl;
        doj.display();
        cout << "Dept: " << this->dept << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "Id: " << this->id << endl;
    }
};

int main()
{
    Employee e;
    e.acceptEmployee();
    e.displayEmployee();
    return 0;
}