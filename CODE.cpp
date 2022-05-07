#include<bits/stdc++.h>
using namespace std;
#define E_a 0.001

double solution(double x) {
   //return pow(x,3) - pow(x,1) - 1;
   return pow(x,3) - x - 4;
}

void bisection(double a, double b) {
   if (solution(a) * solution(b) >= 0) {
      cout << "You have not calculated right a and b\n";
      return;
   }

   double x_o = (a+b)/2;

   while (abs(b-a) > E_a) {
      x_o = (a+b)/2;
      if (solution(x_o) == 0.0)
         break;
      else if (solution(x_o)*solution(a) < 0)
         b = x_o;
      else
         a = x_o;
   }
   cout << "The value of root is : " << x_o;
}
int main() {
   double a =1, b =2;
   bisection(a, b);
   return 0;
}
