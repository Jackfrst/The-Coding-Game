#include<iostream>
using namespace std;

void exp(int age)
{
    if( age >= 20 ) throw 1;
}
int main()
{
    int a;
    cout<<"Whats your age?"<<endl;
    cin>>a;
    try
    {
        exp(a);
        cout<<"You are not permited"<<endl;
    }
    catch(int code)
    {
        cout<<"You are permited"<<endl;
    }
}
