#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
    int top = -1;
    int Size;
    T *arr = NULL;

public:
    Stack()
    {
        cout << "Enter Size of Stack" << endl;
        cin >> Size;
        arr = new T[Size];
    }
    void push(T x)
    {
        if (isFull())
        {
            cout << "Stack Overflow. Cannot process request" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow. Cannot Process Request" << endl;
            return -1;
        }
        T poppedEl = arr[top];
        top--;
        return poppedEl;
    }
    T peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isFull()
    {
        if (top == Size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            /* code */
            cout << arr[i] << endl;
        }
    }

    ~Stack()
    {
        delete[] arr;
    }
};
class Box
{
private:
    int length;
    int breadth;
    int height;

public:
    void accept()
    {
        cout << "Enter length of the box" << endl;
        cin >> length;

        cout << "Enter breadth of the box" << endl;
        cin >> breadth;

        cout << "Enter height of the box" << endl;
        cin >> height;
    }

    void display()
    {
        cout << "Length of the box: " << length << endl;
        cout << "Breadth of the box: " << breadth << endl;
        cout << "Height of the box: " << height << endl;
    }
};
int main()
{
    Stack<Box> st;
    Box b;
    b.accept();
    st.push(b);
    st.peek().display();  // to display user defined type using peek;
    return 0;
}