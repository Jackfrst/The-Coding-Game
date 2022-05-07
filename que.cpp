#include<iostream>
#include<stdlib.h>
#define maxz  20
using namespace std;

int Que[maxz],font = -1 ,rear =-1;
void qinsert(int item)
{
    if (font == 0 && rear  == maxz-1 || font == rear+1 )
    {
        printf("\n\tQueue is Overflow\n\t");
        return;
    }
    if(font == -1) //null que !
    {
        font = 0;
        rear = 0;
    }
    else if( rear == maxz-1 )
    {
        rear = 0;
    }
    else
    {
     rear++;
    }
    Que[rear] = item;
}
int qdelete()
{
    if (font == -1)
    {
        printf("\nQueue is Underflow\n");
        return 0;
    }
    int dltitem = Que[font];
    if (font == rear )
    {
        font=-1;
        rear =-1;
    }
    else if (font == maxz -1 )
    {
        font =0 ;
    }
    else
        font++;

    return dltitem;
}

void display()
{
    int f_pos = font ,r_pos = rear,i;
        printf("\n Queue Contains: \n");
    if(f_pos<=r_pos)
    {
        for(int i=f_pos;i<=r_pos;i++)
        {
           cout<<Que[i];

        }
    }
    else
    {
        while(f_pos<=maxz-1)
        {
            cout<<Que[f_pos];
            f_pos++;
        }
        f_pos=0;
        while(f_pos<=r_pos)
        {
            printf("%d ",Que[f_pos]);
            f_pos++;
        }


    }
    printf("\n");
}

int main()
{
    qinsert(10);
    qinsert(20);
    qinsert(15);
    qinsert(5);
    qinsert(10);
    int i = qdelete();
    display();
    cout<<"\n"<<"The deleted item is "<<i;
    return 0;
}
