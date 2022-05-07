#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int RodCutting(int price[], int n)
{
    int value[n+1];
    value[0] = 0;
    int i, j;

    for (i = 1; i<=n; i++)
    {
        int max_value = INT_MIN;
        for (j = 0; j < i; j++)
        {
            max_value = max(max_value, price[j] + value[i-j-1]);
        }
        value[i] = max_value;
    }
    return value[n];
}
int main()
{
    int arr[] = {1, 7, 12, 25, 5, 22, 18, 16};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout <<endl<<"Maximum Value Obtainable is :"<< RodCutting(arr, size)<<endl;
    return 0;
}
