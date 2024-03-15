#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    int id;
    int salary;

public:
    Employee()
    {
        id = 1;
        salary = 10000;
    }
    Employee(int id, int salary)
    {
        this->salary = salary;
        this->id = id;
    }

    int getSalary()
    {
        return salary;
    }
    void setSalary(int salary)
    {
        this->salary = salary;
    }
    void setId(int id)
    {
        this->id = id;
    }

    void display()
    {
        cout << "EmployeeId: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    void accept()
    {
        cout << "Enter Salary: " << endl;
        cin >> salary;

        cout << "Enter EmployeeId: " << endl;
        cin >> id;
    }
    ~Employee(){
        cout<<"Employee destructor is called"<<endl;
        }
};

class Manager : virtual public Employee
{
private:
    float bonus;

public:
    Manager()
    {
        setSalary(1);
        setId(1);
        setBonus(1);
    }
    Manager(float bonus, int id, float salary)
    {
        this->bonus = bonus;
        setSalary(salary);
        setId(id);
    }
    float getBonus()
    {
        return bonus;
    }
    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }
    virtual void display()
    {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }

    virtual void accept()
    {
        Employee::accept();
        cout << "Enter Bonus: " << endl;
        cin >> this->bonus;
    }
    void displayManager(){
        cout<<"Bonus: "<<bonus<<endl;
    }
    void acceptManager(){
        cout<<"Enter Bonus: "<<endl;
        cin>>bonus;
    }
    ~Manager(){
        cout<<"Manager destructor is called"<<endl;
    }
};
class SalesMan : virtual public Employee
{
private:
    float comm;

public:
    SalesMan()
    {
        setId(1);
        setSalary(1);
        setComm(1);
    }
    SalesMan(int id, float salary, float commision)
    {

        this->setSalary(salary);
        this->setId(id);
        comm = commision;
    }
    float getComm()
    {
        return comm;
    }
    void setComm(float comm)
    {
        this->comm = comm;
    }
    virtual void display()
    {
        Employee::display();
        cout << "Commission: " << comm << endl;
    }

    virtual void accept()
    {
        Employee::accept();
        cout << "Enter Commission: " << endl;
        cin >> this->comm;
    }

    void displaySalesMan()
    {
        cout << "Commission: " << comm << endl;
    }

    void acceptSalesMan()
    {
        cout << "Enter Commission: " << endl;
        cin >> this->comm;
    }
    ~SalesMan(){
        cout<<"SalesMan destructor is called"<<endl;
    }
};
class SalesManager : public Manager, public SalesMan
{
public:
    SalesManager()
    {
        setSalary(1);
        setId(1);
        setBonus(1);
        setComm(1);
    };
    SalesManager(int id, float salary, float bonus, float comm)
    {
        setSalary(salary);
        setId(id);
        setBonus(bonus);
        setComm(comm);
    }

    void display(){
        Employee::display();
        SalesMan::displaySalesMan();
        Manager::displayManager();
        

    }

    void accept(){
     Employee::accept();
     SalesMan::acceptSalesMan();
     Manager::acceptManager();
    }

    ~SalesManager(){
        cout<<"SalesManager destructor is called"<<endl;
    }
};
int main()
{
    SalesManager *e = new SalesManager();
    //All Functionalities tested...
    e->accept();
    e->display();
    delete e;
    return 0;
}