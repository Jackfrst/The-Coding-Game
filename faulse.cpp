#include<bits/stdc++.h>
using namespace std;
#define E_a 0

double func(double x)
{
    return x*x*x - 2*x -5;
}

void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double x_o = 0;
    double x_o1 = 1;

    while (abs(x_o1-x_o) > E_a)
    {
        x_o1 = x_o;
        x_o = (a*func(b) - b*func(a))/ (func(b) - func(a));

        if (func(x_o)==0)
            break;
        else if (func(x_o)*func(a) < 0)
            b = x_o;
        else
            a = x_o;
    }
    cout << "The value of root is : " <<fixed<<setprecision(4)<< x_o;
}

int main()
{
    double a =2, b =3;
    regulaFalsi(a, b);
    return 0;
}
