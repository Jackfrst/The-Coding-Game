#include <bits/stdc++.h>
using namespace std;

int main()
{double X_i = 8.750, N = 3;

stringstream s; // Formating the number to correct value
s<< fixed << setprecision(N) << X_i;
string X_s = s.str();

double X = stod(X_s);

double E_a = (1.0/2.0)* pow(10,-N);  //Calculating Absulute Error
double E_r = (E_a / X); //Calculating Relative Error
double E_p = E_r * 100;  //Calculating Percentage Error

cout<<"The Absolute error Ea is "<< E_a <<endl;
cout<<"The Relative error Er is "<< E_r <<endl;
cout<<"The Percentage error Ep is "<< E_p <<endl;

return 0;
}
