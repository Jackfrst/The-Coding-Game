#include <bits/stdc++.h>
using namespace std;

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
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
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
    int n , x , m;

    cout << "How Many Peoples: ";
    cin >> n;

    cout << endl << "The DNA Length : ";
    cin >> m ;


    int maxSum[n], arr[m];

    for(int i=0; i < n; i++){
        cout << " 7 length DNA sequences for person " << i+1 << ": " ;
        for(int j=0; j < m; j++){
            int x;
            cin >> x;
            arr[j] = x;
        }

        maxSum[i] = maxSubArraySum(arr, 0, n-1);
        int arr[m] ;
    }


    cout << endl << "DNA Amber Mutations are : " <<endl;
    for(int i=0 ; i < n ; i++ )
    {
        cout << "DNA Amber Mutations of person " << i+1 <<" is : "<< maxSum[i]<<endl;
    }


    sort(maxSum,maxSum+n);

    int abs = INFINITY , temp , a ;


    for(int i=0 ; i < n ; i++ )
    {
         temp = maxSum[i] - maxSum[i+1];
            if (temp > abs)
            {
                abs = temp ;
                a = i ;
            }
    }



    cout<< endl << " The minimum is between deference of AMBER MUTASTION person no : "<< a+1 <<" and "<< a+2 << endl ;

    getchar();

    return 0;
}
