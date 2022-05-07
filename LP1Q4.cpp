#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int n,i,j,temp;
    cout<<"Enter The size of your array : ";
    cin>>n;
    int arr[n];

    srand(time(0));

    for(i=0; i<n; i++)
    {
        arr[i]=rand()%100;
    }
    cout<<endl<<"The array that was created is :";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }

    cout<<endl<<endl;

    //____________________Bubbleshort________________

    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1-i; j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<endl<<"\nThe shorted array is :";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }

    cout<<endl<<endl;
    return 0;
}
