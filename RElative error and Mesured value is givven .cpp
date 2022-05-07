#include<bits/stdc++.h>
using namespace std;

int main()
{
    double X_m = 48.0474 , E_r = 0.0042;
    double X = X_m / (1-E_r);
    double E_a = abs(X-X_m);
    double E_p = E_r *100;

    cout<<"The Absolute Error is "<<E_a
  <<"\n The Percentage Error is "<<E_p;

    return 0;
}
