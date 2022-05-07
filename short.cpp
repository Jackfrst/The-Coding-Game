#include <iostream>
using namespace std;

int main()
{
    int n, i , j ,c=0 ;
    cout<<"Input the number of elements you wanna work with : ";
    cin>>n;
    int arr[n],arr1[n];

    cout<<endl<<"Input the elements you wanna work with : ";

    //Input Data
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"The elements are : ";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                arr[i]=arr[j];
            }
            else
            {
                arr[i]=arr[i];
            }
        }
    }
      cout<<endl<<"The elements are : ";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr1[i];
    }



    return 0;
}
