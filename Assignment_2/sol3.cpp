#include<iostream>
using namespace std;
namespace NStudent {
   class Student {
    int rollNo;
    int marks;
    string name;

public:
    void initStudent() {
        rollNo = 1;
        marks = 10;
        name = "N/A";
    }

    void printStudentOnConsole() {
        cout << "Name:  " << name << "  marks: " << marks << "  Roll No.: " << rollNo << endl;
    }

    void acceptStudentFromConsole() {
        cout << "Enter name" << endl;
        cin >> name;
        cout << "Enter Roll No." << endl;
        cin >> rollNo;
        cout << "Enter Marks" << endl;
        cin >> marks;
        cout << "Student has been created in the system!!" << endl;
    }

};
int menu() {
    int option;
    cout << "0:For exit" << endl;
    cout << "1:For initializing default value of Student" << endl;
    cout << "2:For giving your own student details" << endl;
    cout << "3:Printing the details of student" << endl;
    cout << "Enter Your choice" << endl;
    cin >> option;
    return option;
}

}
int main(){
 NStudent::Student s1;
    int choice;
    while ((choice = NStudent::menu()) != 0) {
        switch (choice) {
            case 1:
                s1.initStudent();
                break;

            case 2:
                s1.acceptStudentFromConsole();
                break;

            case 3:
                s1.printStudentOnConsole();
                break;

            default:
                cout << "Wrong Choice" << endl;
                break;

        }
    }
    cout << "Thank you" << endl;

    return 0;
}