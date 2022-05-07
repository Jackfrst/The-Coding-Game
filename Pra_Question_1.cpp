#include <bits/stdc++.h>
using namespace std;

int main(){
  double T_m = 146.2 , T =145.9;

  double E_a = abs(T - T_m);
  double E_r = E_a/T;

  cout<<"The Absolute Error is "<<E_a
  <<"\n The Relative Error is "<<E_r;
return 0;
}
