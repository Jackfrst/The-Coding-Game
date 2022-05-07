#include<iostream>
#include<string.h>
#include<stdlib.h>
#define Maxstk 20

using namespace std;


int stack[Maxstk],top=-1;

void push(int item )
{
  if(top==Maxstk-1)
  {
      cout<<"\nStack is overflow\n";
      return;
  }
  else
  {
      top=top+1;
      stack[top]=item;
  }
}

int pop()
{
    if(top==-1)
    {
        cout<<"\nStack Underflow\n";
        return 0;
    }
    else
    {
        int item=stack[top];
        top--;
        return item;
    }
}

int main()
{
    int i=0;
    char postfix[20];

    cout<<"Enter the postfix expression as variable(as ab+) : ";
    gets(postfix);
    strcat(postfix,")");

     while(postfix[i]!=')')
    {
        char ch=postfix[i];
        if((ch>='a' && ch<='z' )||(ch>='A' && ch <='z'))
        {
            int num;
            cout<<"Enter the value of "<<ch<<" : ";
            cin>>num;
            push(num);
        }
        else
        {
            int A,B,result;
            A=pop();
            B=pop();
            switch(ch)
            {
            case '+':
                result=B+A;
                break;
            case '-':
                result=B-A;
                break;
            case '*':
                result=B*A;
                break;
            case '/':
                result=B/A;
                break;
            }
            push(result);
        }
    i++;
    }

    cout<<"\nThe result is  "<< pop();
    return 0;
}
