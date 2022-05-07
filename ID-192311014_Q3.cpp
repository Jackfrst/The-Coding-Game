#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
    int n,i,j,k,temp,crt=0;
    cout<<"Enter The size of your array : ";
    cin>>n;
    int arr[n],frc[n];

    cout<<endl<<"Enter the element of the array :";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
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
                crt++;
            }
        }
    }

    cout<<endl<<endl;

if(crt==0)
{
    cout<<"\tThe array is shorted";
}
else
    cout<<"\tThe array is not shorted ";
    cout<<endl<<endl;
}
