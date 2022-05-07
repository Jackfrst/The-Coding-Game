#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
    int n,i,j,k,temp;
    cout<<"Enter The size of your array : ";
    cin>>n;
    int arr[n],frc[n];

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

    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
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

    int beg,end,mid,item;

    cout<<"\n\nEnter the element you want to search : ";
    cin>>item;

    beg=0;
    end=n-1;
    mid= int (beg+end)/2;



    while (beg<=end && arr[mid]!=item)
    {
       if(item<arr[mid])
            beg=mid+1;
       else
        end=mid-1;

        mid= (beg+end)/2;
    }

    if(arr[mid]==item)
        cout<<"\n\nSearch successful item found at  Array index  no "<<mid<<endl;
    else
        cout<<"Search is Unsuccessful";

    return 0;

    cout<<endl<<endl<<endl<<endl;
}
