#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int info;
    struct LinkedList *next;
};
typedef struct LinkedList node;
void newlist(node *list)
{
    printf("Enter a item:(-999 to exit):");
    scanf("%d",&list->info);




    if(list->info==-999)




    {
        list->next=0;
    }
    else
    {
        node *newnode;
        newnode= (node*)malloc(sizeof(node));
        list->next=newnode;
        newlist(newnode);
    }

}
void showList(node *list)
{
    printf("List Contains:");
    int sum = 0 ;
    while(list->next!=0)
    {
        printf("%d ",list->info);
        sum += list->info;



        list=list->next;
    }
    printf("\n sum is %d",sum);




}
int main()
{
    node n1;
    node *head;
    head=&n1;
    newlist(head);
    showList(head);




    return 0;
}
