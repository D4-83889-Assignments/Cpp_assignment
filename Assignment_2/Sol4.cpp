#include<iostream>
using namespace std;
class Address
{
private:
    string building;
    string street;
    string city;
    int pin;
    public:
        Address(){
            building = "Wayne Towers";
            city = "Gotham";
            street = "Wayne Mansion Road";
            pin = 2341;
        }
        void accept(){
            cout<<"Enter name of building"<<endl;
            cin>>building;
            cout<<"Enter city name"<<endl;
            cin>>city;
            cout<<"Enter Street name"<<endl;
            cin>>street;
            cout<<"Enter pin "<<endl;
            cin>>pin;
        }
        void display()
        {
            cout<<"Building Name: "<<building<<endl;
            cout<<"City name: "<<city<<endl;
            cout<<"Street Name: "<<street<<endl;
            cout<<"Pin: "<<pin<<endl;
        };
        string getBuilding()
        {
            return building;            
        }
        string getStreet()
        {
            return street;
        }
         string getCity(){
            return city;
         }
        int getPin(){
            return pin;
        }
        void setBuilding(string building)
        {
            this->building = building;
        }
        void setStreet(string setStreet)
        {
            this->street = street;
        };
        void setCity(string city)
        {
            this->city = city;
        }
        void set_pin(int pin){
            this->pin = pin;
        }
    
};

int menu(){
    int choice;
    cout<<"1.To enter details"<<endl;
    cout<<"2.To display details"<<endl;
    cout<<"3.To get city name"<<endl;
    cout<<"4.To get Building name"<<endl;
    cout<<"5.To get pin details"<<endl;
    cout<<"6.To get street details"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    Address A;
    int choice;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:
                A.accept();
                break;
            case 2:
                A.display();
                break;
            case 3:
                cout<<A.getCity()<<endl;
                break;
            case 4:
                cout<<A.getBuilding()<<endl;
                break;
            case 5:
                cout<<A.getPin()<<endl;
                break;
            case 6:
                cout<<A.getStreet()<<endl;
                break;
            default:
                cout<<"Invalid Request"<<endl;
        }   
    }
    cout<<"Thank You!!"<<endl;
    return 0;
}

