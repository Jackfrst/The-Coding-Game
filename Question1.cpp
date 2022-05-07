#include <bits/stdc++.h>
using namespace std;
#define E_a 0

double func(double x)
{
    return pow(x,3) + pow(x,2) - 1; //Declaring the given function
}

void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0) //Checking if the interval we have given is correct
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double x_o;

    int n=0; //Using n to count the number of roots
        int a1;
        int b1;

    while (n<5) // Using n to terminate the process after getting the 5th root
    {
        n++;
        x_o = (a*func(b) - b*func(a))/ (func(b) - func(a)); // Calculating the root

        cout<<"At "<<n<<" itteration interval is "<<a<<" & "<<b;

        //Calculating the new interval
        if (func(x_o)==0)
            break;
        else if (func(x_o)*func(a) < 0)
            b = x_o;
        else
            a = x_o;
        //Printing result for the itteration
        cout<<" And the root is "<<x_o<<endl;
    }
}

int main()
{
    double a =0, b =1; //if we try to solve the equation with 0 and 1
                        //We get func(a) * func(b) <= 0 thus we take them as the interval
    regulaFalsi(a, b); //Using Regular Falsi Method
    return 0;
}
