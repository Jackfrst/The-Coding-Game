#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int cutRod(int price[], int n)
{
    int val[n+1];
    val[0] = 0;

    int i, j;
    for (i = 1; i<=n; i++)
    {
        int max_val = INT_MIN;
        for (j = 0; j < i; j++)
        {
            max_val = max(max_val, price[j] + val[i-j-1]);
        }
        val[i] = max_val;
    }
    return val[n];
}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17,17, 20,24,30};
    int n;
    cout<<"The rod value's are : ";
    cout<<endl<<"Length : 1 2 3 4 5  6  7  8  9  10 ";
    cout<<endl<<"Prices : 1 5 8 9 10 17 17 20 24 30 ";
    cout<<endl<<"Enter the size You want : ";
    cin>>n;
    cout<<endl<<"Maximum Obtainable Value is "<< cutRod(arr, n)<<endl;
    return 0;
}
