#include<bits/stdc++.h>
using namespace std;
#define E_a 0

double solution(double m)
{
    return 4*exp(-m)*sin(m)-1;
}

void bisection(double a, double b)
{
    if (solution(a) * solution(b) >= 0)
    {
        cout << "You have not calculated right a and b\n";
        return;
    }

    double x_o = (a+b)/2;

    while (abs(b-a) > E_a)
    {
        x_o = (a+b)/2;
        if (solution(x_o) == 0.0)
            break;
        else if (solution(x_o)*solution(a) < 0)
            b = x_o;
        else
            a = x_o;
    }
    cout << "The value of root is : " <<fixed<<setprecision(3)<< x_o;
}
int main()
{
    double a =0, b =0.5;
    bisection(a, b);
    return 0;
}
