#include<bits/stdc++.h>
#define EPSILON 0.001
#define E_a  0

using namespace std;

double func(double m)
{
    return 4*exp(-m)*sin(m)-1;
}
double deriv_Func(double m)
{
    return 4*exp(-m)*sin(m) + 4*exp(-m)*cos(m);
}
void newton_Raphson(double b)
{
    double h = func(b) / deriv_Func(b);
    while (abs(func(b)) > E_a)
    {
        h = func(b)/deriv_Func(b);
        b = b - h;
    }
    cout <<setprecision(3)<< fixed<< "The value of the root is : " << b;
}
int main()
{
    double b0 = 0.5;
    newton_Raphson(b0);
    return 0;
}

