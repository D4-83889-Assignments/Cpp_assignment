#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;
    int price;

public:
    virtual void discount() = 0;
    virtual int getDiscountedPrice() = 0;
    int getPrice()
    {
        return price;
    }
    void setPrice(int i)
    {
        price = i;
    }
};
class Book : public Product
{
private:
    string author;
    int discountedPrice;

public:
    void discount()
    {
        discountedPrice = (1 - 0.1) * getPrice();
    }
    int getDiscountedPrice()
    {
        return discountedPrice;
    }
};
class Tape : public Product
{
private:
    string artist;
    int discountedPrice;

public:
    void discount()
    {
        discountedPrice = (1 - 0.05) * getPrice();
    }
    int getDiscountedPrice()
    {
        return discountedPrice;
    }
};
int menu()
{
    int choice;

    cout << "0.Exit" << endl;
    cout << "1.Add a Book" << endl;
    cout << "2.Add a Tape" << endl;
    cout << "Enter Your Choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    int count = 0;
    int cost = 0;
    int price;
    Product **arr = new Product *[3]();
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
            cout << "Enter Right Option" << endl;
        }
        if (arr[count] != NULL)
        {
            cout << "Enter Price" << endl;
            cin >> price;
            arr[count]->setPrice(price);
            arr[count]->discount();
            cost += arr[count]->getDiscountedPrice();
            count++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        /* code */
        delete arr[i];
    }
    delete[] arr;

    cout << "Your bill: " << cost << endl;

    cout << "ThankYou" << endl;
    return 0;
}