#include <iostream>
using namespace std;

class sum{
	int a,b;
	public:
		sum(){};
		sum(int i,int j){
			a=i;
			b=j;
		}
		void show(){
			cout<<a<<"+i"<<b;
		}
		sum operator +(sum);
};
sum sum::operator +(sum obj){
	sum temp;
	temp.a=a+obj.a;
	temp.b=b+obj.b;
	return(temp);
}
int main(){
	sum c1(5,6),c2(7,8),c3;
	cout<<"The 1st no. is:";
	c1.show();
	cout<<"\nThe 2nd no. is:";
	c2.show();
	c3=c1+c2;
	cout<<"\nSum is:";
	c3.show();
}
