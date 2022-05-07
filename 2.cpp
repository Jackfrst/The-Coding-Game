#include <bits/stdc++.h>
using namespace std;

int length ;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            length ++;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            length++;
        }
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h)/2;

    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m+1, h),
               maxCrossingSum(arr, l, m, h));
}

int main()
{
    int n, x, m;

    cout << " Number of Array : ";
    cin >> n;

    cout << endl << "Length Of the array : ";
    cin >> m ;


    int maxSum[n], arr[m];

    for(int i=0; i < n; i++)
    {
        cout << " Enter the element of array no " << i+1 << ": " ;
        for(int j=0; j < m; j++)
        {
            int x;
            cin >> x;
            arr[j] = x;
        }

        maxSum[i] = maxSubArraySum(arr, 0, n-1);
        int arr[m] ;
    }

    cout << endl << "The max sub array sum  " <<endl;
    for(int i=0 ; i < n ; i++ )
    {
        cout << "THe sub array sum of array  " << i+1 <<" is : "<< maxSum[i]<<endl;
    }


    sort(maxSum,maxSum+n);

    getchar();

    return 0;
}
