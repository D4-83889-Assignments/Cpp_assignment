#include<iostream>
using namespace std;

class Tollbooth 
{ 
    unsigned int car;
    double money;

public:

    Tollbooth()
    {
        car= 0;
        money= 0;
    }

    void payingCar()
    {
        car++;
        money+=0.50;
    }
    void noPayCar()
    {
        car++;

    }
    void printOnConsole()
    {
        cout<<"Total Cars = "<<car<<" Total Money = "<<money<<endl;
    
    }
    int menu()
    {
        int choice;
        cout<<"0.Exit:"<<endl;
        cout<<"1.car paying toll:"<<endl;
        cout<<"2.car paying no toll:"<<endl;
        cout<<"3.Check Toll status:"<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin>>choice;
        return choice;
    }

};

    int main()
    {   
        Tollbooth t;
        int choice;
        while ((choice=t.menu())!=0)
        {
            switch (choice)
            {
            case 0:
                cout<<"Thankyou."<<endl;
                break;
            case 1:
                t.payingCar();
                break;
            case 2:
                t.noPayCar();
                break;
            case 3:
                t.printOnConsole();
                break;                
            default:
                cout<<"INVALID."<<endl;
                break;
            }
        }
        
        return 0;
    }
