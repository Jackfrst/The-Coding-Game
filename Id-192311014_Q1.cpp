#include<iostream>
#include<string.h>
#include<stdlib.h>
#define Maxstk 20
using namespace std;

int stack[Maxstk],top=-1;

void push()
{
    cout<<"Enter the element you want to Push :";
    int item;
    cin>>item;
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
    //main();
}

int pop()
{
    if(top==-1)
    {
        cout<<"\nStack Underflow\n";
        return 0 ;
    }
    else
    {
        int item=stack[top];
        top--;
        return item;
    }
}

void display()
{
    int i;
    cout<<"\nThe Stack Element are  : ";
    for(i=0;i<top;i++)
    {
        cout<<stack[i];
    }
    //main();
}

int  main()
{
    int choice ;
    cout<<"Enter 1 for Push()\nEnter 2 for Pop()\nEnter 3 for display()\nEnter 0 for exit.\n";
    cin>>choice;
    switch(choice)
            {
            case 1:
                push();
                break;
            case 2:
                {
                    int d=pop();
                cout<<"The Poped iteam is : "<<d;
                }

                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                {
                    cout<<"Wrong input try again";
                    main();
                }

            }

    return 0;
}
