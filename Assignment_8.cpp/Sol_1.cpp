#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int product = 1;
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        if (n < 0)
        {
            throw 1;
        }
        else
        {
            while (n != 0)
            {
                product *= n;
                n--;
            }
        }
    }
    return product;
}
int main()
{
    int number;
    cout << "Enter a number whose factorial is desired" << endl;
    cin >> number;
    try
    {
       cout<<factorial(number)<<endl;
    }
    catch (...)
    {
        cout << "No. can't be negative" << endl;
    }
    cout << "Program Completed" << endl;
    return 0;
}