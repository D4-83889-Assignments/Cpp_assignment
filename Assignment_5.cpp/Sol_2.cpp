#include <iostream>
using namespace std;

class Product
{
private:
    int id;

protected:
    int price;

public:
    virtual int calDiscount() = 0;
    virtual void acceptPrice() = 0;
};

class Book : public Product
{
private:
    string Title;
    string Author;

public:
    int calDiscount()
    {
        return ((1 - 0.1) * price);
    }
    void acceptPrice()
    {
        cout << "Enter MRP for the book:" << endl;
        cin >> this->price;
    }
};

class Tape : public Product
{
private:
    string Title;
    string Artist;

public:
    int calDiscount()
    {
        return ((1 - 0.05) * price);
    }
    void acceptPrice()
    {
        cout << "Enter MRP for the tape:" << endl;
        cin >> this->price;
    }
};
int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Add a Book" << endl;
    cout << "2.Add a tape" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    Product *arr[3];
    int count = 0;
    int bill = 0;
    while (count < 3 && (choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            arr[count] = new Book();
            break;
        case 2:
            arr[count] = new Tape();
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        if (arr[count] != NULL)
        {
            arr[count]->acceptPrice();
            bill += arr[count]->calDiscount();
            delete arr[count];
            arr[count] = NULL;
            count++;
        }
    }

    cout << "Your bill is : Rs." << bill << endl;

    return 0;
}