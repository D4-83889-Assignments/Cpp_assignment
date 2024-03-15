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

    virtual void display()
    {
        cout << "EmployeeId: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual void accept()
    {
        cout << "Enter Salary: " << endl;
        cin >> salary;

        cout << "Enter EmployeeId: " << endl;
        cin >> id;
    }
    ~Employee()
    {
        cout << "Employee destructor is called" << endl;
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
    void displayManager()
    {
        cout << "Bonus: " << bonus << endl;
    }
    void acceptManager()
    {
        cout << "Enter Bonus: " << endl;
        cin >> bonus;
    }
    ~Manager()
    {
        cout << "Manager destructor is called" << endl;
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
    ~SalesMan()
    {
        cout << "SalesMan destructor is called" << endl;
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

    void display()
    {
        Employee::display();
        SalesMan::displaySalesMan();
        Manager::displayManager();
    }

    void accept()
    {
        Employee::accept();
        SalesMan::acceptSalesMan();
        Manager::acceptManager();
    }

    ~SalesManager()
    {
        cout << "SalesManager destructor is called" << endl;
    }
};
int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Accept Employee" << endl;
    cout << "2.Display the count of all employees with respect to designation " << endl;
    cout << "3.Display All Managers" << endl;
    cout << "4.Display All Salesman" << endl;
    cout << "5.Display All SalesManagers" << endl;
    cout << "Enter Your choice" << endl;
    cin >> choice;
    return choice;
}
int menu2()
{
    int choice;
    cout << "1. Regular Employee" << endl;
    cout << "2. Manager" << endl;
    cout << "3. Sales Man" << endl;
    cout << "4. SalesManager" << endl;
    cout << "Enter your option" << endl;
    cin >> choice;
    return choice;
}

int main()
{

    int choice;
    int option;
    int countEmp = 0;
    int countMan = 0;
    int countSal = 0;
    int countSM = 0;

    Employee *e[10];
    int index = 0;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (index < 10)
            {
                switch (option = menu2())
                {
                case 1:
                    /* code */
                    e[index] = new Employee();
                    index++;
                    break;
                case 2:
                    e[index] = new Manager();
                    index++;
                    break;
                case 3:
                    e[index] = new SalesMan();
                    index++;
                    break;
                case 4:
                    e[index] = new SalesManager();
                    index++;
                    break;
                default:
                    cout << "Wrong option given" << endl;
                    break;
                }
            }

            else
            {
                cout << "Sorry array is full, can't add more employees" << endl;
            }
            break;

        case 2:
            for (int i = 0; i < index; i++)
            {
                /* code */
                if (typeid(*e[i]) == typeid(Employee))
                {
                    countEmp++;
                }
                if (typeid(*e[i]) == typeid(Manager))
                {
                    countMan++;
                }
                if (typeid(*e[i]) == typeid(SalesMan))
                {
                    countSal++;
                }
                if (typeid(*e[i]) == typeid(SalesManager))
                {
                    countSM++;
                }
            }
            cout << "Employees: " << countEmp << endl;
            cout << "Manager: " << countMan << endl;
            cout << "SalesMan: " << countSal << endl;
            cout << "SalesManager: " << countSM << endl;

            break;
        case 3:
            for (int i = 0; i < index; i++)
            {
                /* code */ if (typeid(*e[i]) == typeid(Manager))
                {
                    e[i]->display();
                }
            }

            break;

        case 4:
            for (int i = 0; i < index; i++)
            {
                /* code */ if (typeid(*e[i]) == typeid(SalesMan))
                {
                   e[i]->display();
                }
            }

            break;

        case 5:
            for (int i = 0; i < index; i++)
            {
                /* code */ if (typeid(*e[i]) == typeid(SalesManager))
                {
                    e[i]->display();
                }
            }
            break;

        default:
            cout << "Wrong Case Entered" << endl;
            break;
        }
        countEmp = 0;
        countSal = 0;
        countMan = 0;
        countSM = 0;
    }
    
    cout<<"Thank You"<<endl;
}

