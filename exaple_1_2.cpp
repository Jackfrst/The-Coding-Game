#include<bits/stdc++.h>
using namespace std;

//error from one value

int main()
{
    double X_i = 0.51, N = 2;

    stringstream s;
    s << fixed << setprecision(N) << X_i;
    string X_s = s.str();

    double X = stod(X_s);

    double D_X = (1.0/2.0)* pow(10,-N);
    double P_A = (D_X / X) * 100;

    cout<<"The Absolute error is "<< D_X <<endl;
    cout<<"The Relative error is "<< D_X/X <<endl;
    cout<< fixed << setprecision(N)<<"The percentage error is "<< P_A;

    return 0;
}
