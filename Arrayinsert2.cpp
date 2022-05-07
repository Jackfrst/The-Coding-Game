#include <iostream>
using namespace std;
int main()
{
    int n, i, pos , item ;
    cout<<"Input the number of elements you wanna work with :";
    cin>>n;
    int arr[n];

    cout<<endl<<"Input the elements you wanna work with :";

    //Input Data
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"The elements are :";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }

    cout<<endl<<endl<<"Enter the element you wanna add :";
    cin>>item;

    pos=(n/2);

    for(i=n-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }

    arr[pos]=item;
    n=n+1;

    cout<<endl<<"The new elements are :";
     for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;

}

