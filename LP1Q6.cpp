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

    int arr[row][col],trans[col][row];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cout << "Enter row" << i + 1 << "colum" << j + 1 << ": ";
            cin >> arr[i][j];
            trans[j][i]=arr[i][j];
        }

    cout<<endl<<"The Actual Matrix is : "<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }


    cout << "The Transpose Matrix is :" << endl;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << " " << trans[i][j] << " ";
        }
        cout << endl;
    }


    cout<<endl<<endl;


    return 0;
}
