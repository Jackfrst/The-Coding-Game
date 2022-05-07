#include <iostream>
using namespace std ;
int main()
{
    int n,i,item,pos;
    cout<<"Enter The size of your array : ";
    cin>>n;

    int arr[n];

    cout<<"Enter a array : ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"The array that was created is :";
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<arr[i];
    }

    cout<<endl<<endl<<"Enter element you want to search : ";
    cin>>item;

    i=0;
    while(i<n && item != arr[i])
    {
        i++;
    }

    pos=i;
    if(item==arr[i])
    {
        cout<<endl<<endl<<"Item Found at array index "<<pos<<" "<<endl;
        for(i=pos; i<n-1; i++)
        {
            arr[i]=arr[i+1];
        }
        n=n-1;
        cout<<endl<<"The new array after deleting your item is : ";
        for(i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    else
    {
        cout<<endl<<endl<<"item isn't found";
    }

    cout<<endl<<endl;
    return 0;
}
