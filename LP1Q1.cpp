#include<iostream>
using namespace std;

int main()
{
    int ele,i,j,ctr,sum=0;
    cout<<"Enter the number of element you want : ";
    cin>>ele;

    int arr[ele],uni[ele];

    cout<<endl<<endl;

    cout<<"Enter the elements you want to work with : ";
    for(i=0; i<ele; i++)
    {
        cin>>arr[i];
        uni[i]=-1;
    }

    cout<<endl<<endl;

    for(i=0;i<ele;i++)
    {
        ctr = 1;
        for(j=i+1;j<ele;j++)
        {
            if( arr[i] == arr[j] )
            {
                ctr++;
                uni[j]=0;
            }
        }
        if( uni[i] != 0)
        {
            uni[i] = ctr;
        }
    }

    cout<<"The unique elements are : ";
    for(i=0; i<ele; i++)
    {
        if(uni[i] == 1)
        {
            cout<< arr[i] <<" ";
            sum+=arr[i];
        }
    }

    cout<<endl<<endl;

    cout<<"The sum of the unique element is : "<<sum<<endl<<endl;

    return 0;
}




