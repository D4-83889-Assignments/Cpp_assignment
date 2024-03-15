#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Course
{
private:
    int id;
    string courseName;
    int fee;

public:
    void accept()
    {
        cout << "Enter id no. " << endl;
        cin >> id;

        cout << "Enter course name" << endl;
        cin >> courseName;

        cout << "Enter fee" << endl;
        cin >> fee;
    }

    void display()
    {
        cout << "Course Id: " << id << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Fee: " << fee << endl;
    }
};
class Student
{
private:
    int roll_no;
    string name;
    vector<Course *> courseList;

public:
    Student()
    {
        roll_no = 1;
        name = "N/A";
    }

    void accept()
    {
        Course *ptr = NULL;
        cout << "Enter Roll No: " << endl;
        cin >> roll_no;

        cout << "Enter name: " << endl;
        cin >> name;

        ptr = new Course();
        ptr->accept();
        courseList.push_back(ptr);
    }

    void acceptCourse()
    {
        Course *ptr = NULL;
        ptr = new Course;
        ptr->accept();
        courseList.push_back(ptr);
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "rollNo: " << roll_no << endl;
        cout << "Courses Enrolled: " << endl;

        for (int i = 0; i < courseList.size(); i++)
        {
            /* code */
            courseList[i]->display();
        }
    }
    ~Student(){
        for (int i = 0; i < courseList.size(); i++)
        {
            /* code */
            delete courseList[i];
        }
        
    }
};

int menu()
{

    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Add a student" << endl;
    cout << "2.Add course to an existing student" << endl;
    cout << "3.Display all students" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    return choice;
}

int main()
{

    int choice;
    Student *ptr;
    int i;
    vector<Student *> studentList;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            ptr = new Student;
            ptr->accept();
            studentList.push_back(ptr);
            break;
        case 2:
            cout << "Enter student index to increment his/her courses.." << endl;
            cin >> i;
            if (i > studentList.size())
            {
                cout << "Student does not exits, add him first" << endl;
            }
            else
            {

                studentList[i]->acceptCourse();
            }

            break;
        case 3:
            for (int i = 0; i < studentList.size(); i++)
            {
                /* code */
                studentList[i]->display();
            }

            break;
        default:
            cout << "Wrong choice entered" << endl;
            break;
        }
    }

    cout << "Thanks for using the application." << endl;
    for (int i = 0; i < studentList.size(); i++)
    {
        /* code */delete studentList[i];
    }
    
    return 0;
}