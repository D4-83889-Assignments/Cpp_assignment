#include <iostream>
using namespace std;
class Matrix
{
    int row;
    int col;
    int **arr = NULL;
    int currentIndexRow = 0;
    int currentIndexCol = 0;

public:
    Matrix()
    {
        cout << "Enter size of matrix: " << endl;
        cin >> row;
        col = row;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            /* code */
            arr[i] = new int[col];
        }
    }
    Matrix(int val)
    {
        cout << "Enter size of matrix: " << endl;
        cin >> row;
        col = row;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            /* code */
            arr[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                /* code */
                arr[i][j] = val;
            }
        }
    }
    void accept(int val)
    {
        if (currentIndexRow < row && currentIndexCol < col)
        {
            arr[currentIndexRow][currentIndexCol] = val;
            currentIndexCol++;
            if (currentIndexCol >= col)
            {
                currentIndexCol = 0;
                currentIndexRow++;
            }
        }
        else
        {
            cout << "Matrix is full. Cannot accept more values." << endl;
        }
    }
    void print()
    {
        for (int i = 0; i < row; i++)
        {
            /* code */
            for (int j = 0; j < col; j++)
            {
                /* code */
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void transpose()
    {
        int temp;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                /* code */
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        print();
    }
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    int **getArr()
    {
        return arr;
    }
    ~Matrix()
    {
        for (int i = 0; i < row; i++)
        {
            /* code */
            delete[] arr[i];
        }
        delete[] arr;
    }
};
void add(Matrix &m1, Matrix &m2)
{
    int **arr1 = m1.getArr();
    int **arr2 = m2.getArr();
    for (int i = 0; i < m1.getRow(); i++)
    {
        /* code */
        for (int j = 0; j < m2.getCol(); i++)
        {
            arr1[i][j] += arr2[i][j];
        }
    }
}
void subtract(Matrix &m1, Matrix &m2)
{
    int **arr1 = m1.getArr();
    int **arr2 = m2.getArr();
    for (int i = 0; i < m1.getRow(); i++)
    {
        /* code */
        for (int j = 0; j < m1.getCol(); j++)
        {
            /* code */
            arr1[i][j] -= arr2[i][j];
        }
    }
}
void multiply(Matrix &m1, Matrix &m2)
{
    int **arr1 = m1.getArr();
    int **arr2 = m2.getArr();
    int arr3[m1.getRow()][m2.getCol()];
    int p = m1.getRow();
    for (int i = 0; i < m1.getRow(); i++)
    {
        /* code */
        for (int j = 0; j < m1.getCol(); j++)
        {
            /* code */
            for (int k = 0; i < m1.getRow(); i++)
            {
                /* code */
                arr3[i][j] = arr1[i][k] * arr2[k][j];
            }
        }
    }
    for (int i = 0; i < m1.getRow(); i++)
    {
        /* code */
        for (int j = 0; j < m2.getCol(); j++)
        {
            /* code */
            arr1[i][j] = arr3[i][j];
        }
    }
}
int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Accept a Value for matrix.." << endl;
    cout << "2.Print Matrix" << endl;
    cout << "3.Print Transpose" << endl;
    cout << "4.Add Matrices" << endl;
    cout << "5.Multiply Matrices" << endl;
    cout << "6.Subtract Matrices" << endl;
    cout << "Enter Choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    Matrix m1;
    Matrix m2;
    int val;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:

            cout << "Enter a Value for matrix 1" << endl;
            cin >> val;
            m1.accept(val);
            cout << "Enter a Value for matrix 2" << endl;
            cin >> val;
            m2.accept(val);

            break;

        case 2:
            cout << "Printed Matrix:" << endl;
            m1.print();
            m2.print();
            break;
        case 3:
            cout<<"transpose of matrices:"<<endl;
            m1.transpose();
            m2.transpose();
            
            break;

        case 4:
            add(m1, m2);
            cout << "Added matrices" << endl;
            break;
        case 5:
            multiply(m1, m2);
            cout << "Multiplied matrices" << endl;
            break;
        case 6:
            subtract(m1, m2);
            cout << "Subtracted matrices" << endl;
            break;
        default:
            cout << "Wrong Input" << endl;
        }
    }
    cout << "Thankyou" << endl;
    return 0;
}
