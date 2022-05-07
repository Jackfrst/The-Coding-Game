#include<iostream>
using namespace std;
int main()
{
    int n,i,j,cnt=0,k=0;
    cout<<"Enter the number of element you wanna work with : ";
    cin>>n;
    int arr[n],freq[n];
    cout<<endl<<"Enter the elements of the array : ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        freq[i]=-1;
    }

    for(i=0; i<n; i++)
    {
        cnt=1;
        for(j=i+1; j<n; k++)
        {
            if(arr[i]==arr[k])
            {
                cnt++;
                freq[j] = 0;
            }
        }
        if(freq[i]!=0)
        {
            freq[i]=cnt ;
        }
    }

    cout<<"\n\nThe Unique elements are : ";
    for(i=0;i<n;i++)
    {
        if(freq[i]==1)
        {
            cout<<" "<<arr[i];
            k++;
        }
    }
    cout<<"\n\nThe amount of unique elements is : "<<k;
    cout<<endl;

    return 0;
}
