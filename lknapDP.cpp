#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapDP(int MaxW, int weight[], int value[], int n)
{
    int i, j;
    int arr[n + 1][MaxW + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= MaxW; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                arr[i][j] = max(value[i - 1]+ arr[i - 1][j - weight[i - 1]],
                                arr[i - 1][j]);
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }

    return arr[n][MaxW];
}

int main()
{
    int value[] = { 40, 200, 220 };
    int weight[] = { 10, 20, 30 };
    int MaxW = 50;
    int n = sizeof(value) / sizeof(value[0]);
    cout <<"The maximum value that can be carried is : "<< knapDP(MaxW, weight, value, n)<<endl;
    return 0;
}
