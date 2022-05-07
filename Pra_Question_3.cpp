#include<bits/stdc++.h>
using namespace std;

int main()
{
    double X_i = 8.6, N = 1;

    stringstream s;
    s << fixed << setprecision(N) << X_i;
    string X_s = s.str();

    double X = stod(X_s);

    double E_a = (1.0/2.0)* pow(10,-N);
    double E_r = E_a / X;

    cout<<"The Relative error is "<< fixed << setprecision(5)<< E_r;

    return 0;
}
