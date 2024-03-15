#include <iostream>
#include <vector>
using namespace std;

class Person
{
private:
    string name;

public:
    virtual void acceptData()
    {
        cout << "Enter name - ";
        cin >> name;
    }
    virtual void displayData()
    {
        cout << "Name - " << name << endl;
    }
};

class Student : public Person
{
private:
    int rollno;
    double marks;

public:
    void acceptData()
    {
        cout << "Enter rollno - ";
        cin >> rollno;

        Person::acceptData();

        cout << "Enter marks - ";
        cin >> marks;
    }
    void displayData()
    {
        cout << "Rollno - " << rollno << endl;
        Person::displayData();
        cout << "Marks - " << marks << endl;
    }
};

class Employee : public Person
{
private:
    int empid;
    double salary;

public:
    void acceptData()
    {
        cout << "Enter empid - ";
        cin >> empid;

        Person::acceptData();

        cout << "Enter Salary - ";
        cin >> salary;
    }

    void displayData()
    {
        cout << "Empid - " << empid << endl;

        Person::displayData();

        cout << "Salary - " << salary << endl;
    }
};

int menu()
{
    int choice;
    cout << "0. EXIT" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Display Employees" << endl;
    cout << "4. Display Students" << endl;
    cout << "5. Display All Persons" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    int index = 0;

    vector<Person*> persons;
    Person* ptr = NULL;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
          
           
                ptr = new Employee();
                ptr->acceptData(); // upcasting
                persons.push_back(ptr);
                index++;
            
            break;
        case 2:
           
                ptr = new Student(); // upcasting
                persons.push_back(ptr);
                persons[index]->acceptData();    //
                index++;
                
            break;
        case 3:
            for (int i = 0; i < index; i++)
                if (typeid(*persons[i]) == typeid(Employee))
                    persons[i]->displayData();
            // cout << "Type - " << typeid(*persons[i]).name() << endl;
            break;
        case 4:
            for (int i = 0; i < index; i++)
                if (typeid(*persons[i]) == typeid(Student))
                    persons[i]->displayData();
            break;
        case 5:
            for (int i = 0; i < index; i++)
                persons[i]->displayData();
            break;
        default:
            cout << "Wrong choice ..." << endl;
            break;
        }
    }

    for (int i = 0; i < index; i++)
        delete persons[i];

    cout << "Thank you ... " << endl;
    return 0;
}