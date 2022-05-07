#include <bits/stdc++.h>
using namespace std;

int main(){
  double TrueMeasuredValue = 146.2 , TrueValue =145.9;

  double Error_absolute = abs(TrueValue - TrueMeasuredValue);
  double Error_relative = Error_absolute/TrueValue;
  double Error_percentage = Error_relative * 100;

  cout<<"The Absolute Error is "<<Error_absolute
  <<"\nThe Relative Error is "<<Error_relative
  <<"\nThe Percentage Error is "<<Error_percentage
  <<endl;
return 0;
}
