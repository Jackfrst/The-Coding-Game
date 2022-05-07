#include<bits/stdc++.h>
using namespace std;

class FIB
{

public:
    int fib(int n)
    {

        int arr[n + 2];
        int i;

        arr[0] = 0;
        arr[1] = 1;

        for(i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};

int main ()
{
    FIB g;
    int n ;
    cout<<"Enter the Fibonacci position : ";
    cin>>n;

    cout <<endl<<"The Fibonacci number is :"<< g.fib(n);
    return 0;
}
