#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int info;
    struct LinkedList *next;
};
typedef struct LinkedList node;
void createList(node *list)
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
        createList(newnode);
    }



}
void printList(node *list)
{
    printf("List Contains:");
    while(list->next!=0)
    {
        printf("%d ",list->info);
//        if(list->next->next==0)
//            printf("%d ",list->next->info);
        list=list->next;
    }
}
int main()
{
    node n1;
    node *head;
    head=&n1;
    createList(head);
    printList(head);
    return 0;
}
