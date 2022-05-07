#include<iostream>
using namespace std;

int main()
{
    double X1 = 3.1428571, X = 3.1415926;
    double E_a = abs(X-X1);
    double E_r = E_a/X;
    double E_p = (E_r * 100);

    cout<<"Absolute error : "<<E_a<<"\n"<<
        "Relative error : "<<E_r<<"\n"<<
        "Percentage error : "<<E_p<<"\n";
    return 0;
}
