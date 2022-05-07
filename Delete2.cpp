#include <iostream>
using namespace std;

int main()
{
    int n, i, pos, item ;
    cout<<"Input the number of elements you wanna work with : ";
    cin>>n;
    int arr[n];

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

    pos=(n/2)-1;

    item=arr[pos];
    for(i=pos; i<n; i++)
    {
        arr[i]=arr[i+1];
    }
    n=n-1;

    cout<<endl<<endl<<"\nThe Deleted data is : "<<item<<endl;
    cout<<endl<<"The new elements are : ";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;

}
