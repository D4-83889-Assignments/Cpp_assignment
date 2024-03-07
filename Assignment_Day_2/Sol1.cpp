#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int breadth;
    int height;

public:
    Box()
    {
        length = 1;
        breadth = 1;
        height = 1;
    }
    void acceptValue()
    {
        cout << "Enter Length: " << endl;
        cin >> length;
        cout << "Enter Breadth: " << endl;
        cin >> breadth;
        cout << "Enter Height: " << endl;
        cin >> height;
        cout << "Length " << length << " Breadth: " << breadth << " height " << height << endl;
    }
    void printValue()
    {
        cout << "Length " << length << " Breadth: " << breadth << " height " << height << endl;
    }

    void calVolume()
    {
        cout << height * length * breadth<<endl;
    }
};

int menu()
{
    int option;
    cout << "0. Exit" << endl;
    cout << "1. Create a box using your Values" << endl;
    cout << "2. Print Dimensions of the box" << endl;
    cout << "3. Calculate Volume of the box and display result" << endl;
    cout << "Enter Choice" << endl;
    cin >> option;
    return option;
}

int main()
{
    Box B1;

    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            B1.acceptValue();
            break;

        case 2:
            B1.printValue();
            break;

        case 3:
            B1.calVolume();
            break;
        default:
            cout << "Invalid Choice!!";
        }
    }

    cout << "Thankyou!!!" << endl;
}