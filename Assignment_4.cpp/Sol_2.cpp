#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    string gender;
    int rollNo;

    float per;
    int marks1;
    int marks2;
    int marks3;

public:
    Student()
    {
        name = "N/a";
        gender = "N/a";
        rollNo = 1;
    }
    void accept()
    {

        cout << "Enter name: " << endl;

        cin >> this->name;
        cout << "Enter Gender" << endl;
        cin >> this->gender;
        cout << "Enter Roll No" << endl;
        cin >> this->rollNo;
        cout << "Enter marks out 100 in 3 Subjects" << endl;
        cin >> marks1;
        cin >> marks2;
        cin >> marks3;
        per = (float((marks1 + marks2 + marks3) / 300.0)) * 100;
    }
    void display()
    {
        cout << "Name: " << this->name << endl;
        cout << "Gender: " << this->gender << endl;
        cout << "RollNo: " << this->rollNo << endl;
        cout << "Percentage: " << this->per << endl;
    }

    int getRollNo()
    {
        return rollNo;
    }
    string getName(){
        return this->name;
    }
};

void sortRecords(Student arr[], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        /* code */
        for (int j = 0; j < Size - i - 1; j++)
        {
            if (arr[j + 1].getRollNo() < arr[j].getRollNo())
            {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void searchRecords(Student arr[], int Size, int rollNo)
{

    for (int i = 0; i < Size; i++)
    {
        if (arr[i].getRollNo() == rollNo)
        {
            cout << "Searched Record: " << endl;
            arr[i].display();
        }
        else
        {
            cout<<"Record Not Found"<<endl;
        }
    }
}
void searchRecords(Student arr[], int Size, string name)
{

    for (int i = 0; i < Size; i++)
    {
        if (arr[i].getName() == name)
        {
            cout << "Searched Record: " << endl;
            arr[i].display();
            break;
        }
        else
        {
            cout<<"Record Not Found"<<endl;
        }
    }
}
void displayAll(Student arr[], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        /* code */
        arr[i].display();
    }
}
void acceptAll(Student arr[], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        /* code */
        arr[i].accept();
    }
}
int menu()
{
    int choice;
    cout<<"***********************"<<endl;
    cout << "0. Exit" << endl;
    cout << "1. Display" << endl;
    cout << "2. Accept" << endl;
    cout << "3. SortRecords" << endl;
    cout << "4. Search By Name" << endl;
    cout << "5. Display All Data" << endl;
    cout << "Enter Your Choice" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    int Size;
    int i;
    int res;
    string name;
    cout << "Enter No. of Students" << endl;
    cin >> Size;
    Student *arr = new Student[Size];

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter index of student to display particular record" << endl;
            cin >> i;
            arr[i].display();
            break;

        case 2:
            cout << "Enter index of student whose value you want to modify" << endl;
            cin >> i;
            arr[i].accept();
            break;

        case 3:
            sortRecords(arr, Size);
            break;
        case 4:
            cout << "Enter Name" << endl;
            cin >> name;
            searchRecords(arr, Size, name);
            break;
        case 5:
            displayAll(arr, Size);
            break;
        default:
            cout << "Wrong Input" << endl;
        }
    }
    cout << "Thank You!!!" << endl;
    return 0;
}