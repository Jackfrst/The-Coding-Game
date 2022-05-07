#include <iostream>
#include <stdlib.h>
using namespace std;
int main ()
{
    int n,i;
    cout<<"Enter The size of your array : ";
    cin>>n;

    int arr[n];

    cout<<"Enter a shorted array : ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"The array that was created is :";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }

    //____________BinarySearch____________
    int beg,end,mid,item;

    cout<<"\n\nEnter the element you want to search : ";
    cin>>item;

    beg=0;
    end=n-1;
    mid= int (beg+end)/2;



    while (beg<=end && arr[mid]!=item)
    {
        if(item>arr[mid])
            beg=mid+1;
        else
            end=mid-1;

        mid= int(beg+end)/2;
    }

    if(arr[mid]==item)
        cout<<"\n\nSearch successful item found at  Array index  no "<<mid<<endl;
    else
    {
        int pos;
        cout<<endl<<" \a !!!! The element is not in the array !!!! \a"<<endl;

        //____________Position_______

        for(i=0; i<n; i++)
        {
            if(item>arr[i])
            {
            }
            else
            {
                break;
            }
        }
         pos=i;

        //______________Insertion___________


        for(i=n-1; i>=pos; i--)
        {
            arr[i+1]=arr[i];
        }

        arr[pos]=item;
        n=n+1;

        cout<<endl<<"After adding the element  new Array is  : ";
        for(i=0; i<n; i++)
        {
            cout<<"\t"<<arr[i];
        }

    }

    cout<<endl<<endl<<endl<<endl;

    return 0;
}

