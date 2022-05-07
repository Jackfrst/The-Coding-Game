#include<bits/stdc++.h>
using namespace std;



int main()
{
    double TrueValue = 8.6, Number_of_decimalPoint = 1;

    stringstream s;
    s << fixed << setprecision(Number_of_decimalPoint) << Number_of_decimalPoint;
    string Number_of_decimalPoint = s.str();

    double X = stod(Number_of_decimalPoint);

    double D_X = (1.0/2.0)* pow(10,-N);
    double P_A = (D_X / X) * 100;

    cout<<"The Absolute error is "<< D_X <<endl;
    cout<<"The Relative error is "<< D_X/X <<endl;
    cout<< fixed << setprecision(N)<<"The percentage error is "<< P_A;

    return 0;
}
