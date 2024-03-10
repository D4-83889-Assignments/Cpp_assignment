#include <iostream>
using namespace std;

class Stack
{
    int top = -1;
    int Size;
    int *arr = NULL;
    
    public: 
    
    Stack(){
        cout<<"Enter Size of Stack"<<endl;
        cin>>Size;
        arr = new int[Size];
    }
    void push(int x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow. Cannot process request"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow. Cannot Process Request"<<endl;
            return -1;
        }
        int poppedEl = arr[top];
        top--;
        return poppedEl;
    }
    int peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        if(top==-1)
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
        if(top==Size-1)
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
            cout<<arr[i]<<endl;
        }
        
    }

    ~Stack(){
        delete []arr;
    }

};
int menu(){
    int choice;
    cout<<"0.Exit"<<endl;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Peek"<<endl;
    cout<<"4.Check if stack is empty"<<endl;
    cout<<"5.Check if stack is full"<<endl;
    cout<<"6.Print Stack"<<endl;

    cout<<"Enter Your Choice"<<endl;
    cin>>choice;
    return choice;

}
int main()
{   
    int choice;
    Stack s;
    int n;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter an element to push onto the stack"<<endl;
                cin>>n;
                s.push(n);
                break;

            case 2:
                cout<<"Popped Element: "<<s.pop()<<endl;
                break;
            case 3:
                cout<<"Top Element is "<<s.peek()<<endl;
                break;
            case 4:
                if(s.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<"Stack is not Empty"<<endl;
                }
                break;
            case 5:
                  if(s.isFull())
                {
                    cout<<"Stack is Full"<<endl;
                }
                else
                {
                    cout<<"Stack is not Full"<<endl;
                }
                break;
            case 6:
                s.printStack();
                break;
            default:
                cout<<"Wrong Choice"<<endl;
                break;
        }
    }
    
    cout<<"ThankYou.."<<endl;
 
    return 0;
}