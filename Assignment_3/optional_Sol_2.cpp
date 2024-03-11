#include <iostream>

using namespace std;
class Employee
{
private:
    const int empid;
    int salary;
    static int genId;
    string Name;

public:
    Employee() : empid(++genId)
    {
        Name = "N/A";
        salary = 10000;
    }
    void AddEmp()
    {
        cout << "Enter Employee Name" << endl;
        cin >> Name;
        cout << "Enter Salary" << endl;
        cin >> salary;
    }
    int getId()
    {
        return empid;
    }
    void printEmployee()
    {
        cout << "NAME: " << Name << "  EMPID: " << getId() << " SALARY: " << salary << endl;
    }
    static void SearchEmployee()
    {
    }
};
int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Add an Employee" << endl;
    cout << "2.Search An Employee" << endl;
    cout << "3.Display All Employees" << endl;
    cout << "Enter Your Choice" << endl;
    cin >> choice;
    return choice;
}
int Employee::genId = 120;
void ViewEmployee(int empid)
{
}
int main()

{
    int Size, choice;
    cout << "Tell me number of employee for your organization" << endl;
    cin >> Size;
    Employee **arr = new Employee *[Size]();
    int i = 0;
    int empid;
    int genId = 120;
    int top =-1;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            // Add/Accept an Employee
            if(top<Size-1){
            arr[i] = new Employee();
            arr[i]->AddEmp();
            i++;}
            else{
                cout<<"No more Employee can be added.."<<endl;
            }
            break;
        case 2:
            // Search an Employee
            cout << "Enter employee id" << endl;
            cin >> empid;
            if (empid > genId + Size)
            {
                cout << "Employee Doesn't Exists" << endl;
            }
            else if (empid <= genId)
            {
                cout << "Enter Correct ID" << endl;
            }
            else
            {
                int k = 0;
                while (arr[k]->getId() != empid && k < Size)
                {
                    k++;
                }
                arr[k]->printEmployee();
            }
            break;

        case 3:

            for (int i = 0; i < Size; i++)
            {
                /* code */
                arr[i]->printEmployee();
            }

            break;

        default:
            cout << "Wrong Input" << endl;
        }
    }
    cout << "Thankyou!!" << endl;
    for (int i = 0; i < Size; i++)
    {
        /* code */
        delete arr[i];

    }
    delete []arr;
    
    return 0;
}