#include<bits/stdc++.h>
#define EPSILON 0.001
#define E_a  0

using namespace std;

double func(double b)
{
    return pow(b,3) - b - 4;//sin(b)- (10*b) - 10;
}

double deriv_Func(double b)
{
    return 3*pow(b,2)- 1;//cos(b)- 10;
}

void newton_Raphson(double b)
{
    double h = func(b) / deriv_Func(b);
    double n =0;
    while (abs(func(b)) > E_a)
    {
        n++;
        h = func(b)/deriv_Func(b);
        b = b - h;
        cout<<"At "<<n<<" itteration root is "<<b<<endl;
    }

    cout <<setprecision(3)<< fixed<< "The value of the root is : " << b;
}

int main()
{
    double b0 = 1.5;
    newton_Raphson(b0);
    return 0;
}
