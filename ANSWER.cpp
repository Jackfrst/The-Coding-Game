#include<bits/stdc++.h>
#define EPSILON 0.001
#define E_a  0

using namespace std;

double func(double b)
{
    return sin(b)- (10*b) - 10;
}

double deriv_Func(double b)
{
    return cos(b)- 10;
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
    double b0 = 1;
    newton_Raphson(b0);
    return 0;
}
