#include<iostream>
using namespace std;

int main()
{
    int num,i,o=0,e=0;
    cout<<"Enter the number of elements you wanna work with :";
    cin>>num;
    int arr[num],even[num],odd[num];
    cout<<"Enter the elements you wanna work with : ";
    for(i=0; i<num; i++)
    {
        cin>>arr[i];
        if(arr[i]%2==0)
        {
            even[e]=arr[i];
            e++;
        }
        else
        {
            odd[o]=arr[i];
            o++;
        }
    }
    cout<<endl<<endl<<"\t\t\tThe out-put "<<endl<<endl;
    cout<<"The number of even elements that you have is : "<<e<<endl;
    cout<<"The number of odd  elements that you have is : "<<o<<endl;

    cout<<endl<<"The even numbers are :";
    for(i=0; i<e; i++)
    {
        cout<<" "<<even[i];
    }
    cout<<endl<<"The Odd  numbers are :";
    for(i=0; i<o; i++)
    {
        cout<<" "<<odd[i];
    }

    cout<<endl;
    return 0;
}
