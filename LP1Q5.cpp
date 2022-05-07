#include <iostream>
using namespace std;
int main()
{
    int row, col, summ = 0;

    cout << "Enter Number of Row : ";
    cin >> row;
    cout <<endl<< "Enter Number of Column : " ;
    cin >> col;
    cout<<endl;

    int arr[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cout << "Enter row" << i + 1 << "colum" << j + 1 << ": ";
            cin >> arr[i][j];
            summ += arr[i][j];
        }
    cout <<endl<< "Sum of the matrix: " << summ;
    return 0;
}


