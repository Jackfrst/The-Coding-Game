#include <stdio.h>
#include <stdlib.h>
#define MAXSZ 8
int Queue[MAXSZ],front=-1,rear=-1;
void queueInsert(int item)
{
    if((front==0 &&rear==MAXSZ-1)||front==rear+1)
    {
        printf("Queue is overflow !!\n");
        return;
    }
    if(front==-1)// check queue is empty
    {
        front=0;
        rear=0;

    }
    else if(rear==MAXSZ-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }

    Queue[rear]=item;


}
int queueDelete()
{
    if(front==-1)
    {
        printf("Queue is Underflow !!!\n");
        return ;
    }
    int del_item=Queue[front];

    if(front==rear)
        {
            front=-1;
            rear=-1;
        }

        else if(front==MAXSZ-1)
        {
            front=0;
        }
        else
            front=front+1;


        return del_item;

}
void display()
{
    printf("\n Queue Contains: \n");
    int f_pos=front,r_pos=rear;
    if(f_pos<=r_pos)
    {
        for(int i=f_pos;f_pos<=r_pos;i++)
        {
            printf("%d ",Queue[i]);

        }
    }
    else
    {
        while(f_pos<=MAXSZ-1)
        {
            printf("%d ",Queue[f_pos]);
            f_pos++;
        }
        f_pos=0;
        while(f_pos<=r_pos)
        {
            printf("%d ",Queue[f_pos]);
            f_pos++;
        }


    }
    printf("\n");

}
int main()
{
    queueInsert(10);
    queueInsert(20);
    queueInsert(15);
    queueInsert(25);
    queueInsert(5);

    printf("\nFront =%d \n",front);
    printf("Rear =%d ",rear);
//    queueDelete();
//    queueInsert(50);
//    queueInsert(55);
//    queueInsert(65);
//    queueInsert(35);//output
//
//    display();
//
//
//    queueDelete();
//
//    //display()
//    display();
//
//    queueDelete();
//    queueDelete();
//    queueDelete();
//    display();
//
//    printf("\nFront =%d \n",front);
//    printf("Rear =%d ",rear);


    return 0;
}
