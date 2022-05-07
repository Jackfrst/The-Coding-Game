#include<iostream>
using namespace std;
int main ()
{
   int num,i,even=0,odd=0;

   cout<<endl<<"Enter the amount of elements you wanna work on : ";
   cin>>num;
   int arr[num];
   cout<<"Enter the elements you wanna work on : ";
   for(i=0;i<num;i++)
   {
       cin>>arr[i];
     if(arr[i]%2==0)
     {
         even++;
     }
     else
     {
         odd++;
     }
   }
   cout<<endl<<endl<<"\t\t\tThe out-put "<<endl<<endl;
   cout<<"The number of even elements that you have is : "<<even<<endl;
   cout<<"The number of odd  elements that you have is : "<<odd<<endl;
    return 0;
}
