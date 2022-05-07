#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MaxStk 20



int stack[MaxStk],top=-1;
void push(int item)
{
    if(top==MaxStk-1)
    {
        printf("\nStack is overflow\n");
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
        printf("\nStack Underflow !!!!\n");
    }
    else{
        int item=stack[top];
        top--;
        return item;
    }



}
void display()
{
    printf("\nStack Contains\n");
    for(int i=0;i<=top;i++)
        printf("%d ",stack[i]);
}
int main()
{
//    push(20);
//    push(30);
//    push(50);
//    push(25);
//
//    printf("\nDeleted element: %d" ,pop());
//    printf("\nDeleted element: %d" ,pop());
//    push(100);
//
//    printf("\nDeleted element: %d" ,pop());
//
//    //display();



    char postfix[20];



    printf("enter the postfix expression:");
    gets(postfix);
    strcat(postfix,")");
    int i=0;
    while(postfix[i]!=')')
    {
        char ch=postfix[i];
        if(ch>='0' && ch<='9')
        {
            push(ch-'0');//atoi(ch)
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



    printf("Result is :%d",pop());



    return 0;
}
