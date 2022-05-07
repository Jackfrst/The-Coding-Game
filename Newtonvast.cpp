#include<bits/stdc++.h>

#define    f(x) pow(x,3) - x - 4   //sin(x)- (10*x) - 10

#define   g(x)  3*x - 1 //cos(x)- 10

using namespace std;

int main()
{
	 float x0, x1, f0, f1, g0, e;
	 int step = 1, N;

     cout<< setprecision(6)<< fixed;

     /* Inputs */
	 cout<<"Enter initial guess: ";
	 cin>>x0;
	 cout<<"Enter tolerable error: ";
	 cin>>e;
	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 cout<< endl<<"*********************"<< endl;
	 cout<<"Newton Raphson Method"<< endl;
	 cout<<"*********************"<< endl;
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   cout<<"Mathematical Error.";
			   exit(0);
		  }


		  x1 = x0 - f0/g0;


		  cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x1<<" and f(x) = "<< setw(10)<< f(x1)<< endl;
		  x0 = x1;

		  step = step+1;

		  if(step > N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }

		  f1 = f(x1);

	 }while(fabs(f1)>e);

	 cout<< endl<<setprecision(3)<< fixed<<"Root is: "<< x1;
	 return 0;
}
