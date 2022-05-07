#include<bits/stdc++.h>
using namespace std;

void printMaxActivities(int a[], int b[], int n,const char *name[])
{
    int i, j, ct=1;

    cout<<"Following activities are selected : "<<endl;


    i = 0;
    cout<<" "<<name[i]<<endl;


    for (j = 1; j < n; j++)
    {
        if (a[j] >= b[i])
        {
            cout<<" "<<name[j]<<endl;
            i = j;
            ct++;
        }
    }
    cout<<endl<<" The number of task can be executed is : "<<ct<<endl;
}

int main()
{
    const char *name[] = { "Google Chrome ", "Foxit Reader ", "VS Code ", "Drive " , "MS Teams " , "Libre Office","Kernel Module ", "Crash Handler" , "Google Chrome-1 " ,"SSL Key","Whats App"};
    int a[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int b[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    int n = sizeof(a)/sizeof(a[0]);

    printMaxActivities(a, b, n,name);
    return 0;
}
