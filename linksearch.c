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
    int sum=0,count=0;
    printf("List Contains:");
    while(list->next!=0)
    {
        count++;
        printf("%d ",list->info);
        sum=sum+list->info;
// if(list->next->next==0)
// printf("%d ",list->next->info);
        list=list->next;
    }
    printf("\nTotal node %d",count);
    printf("\nSum is :%d\n",sum);

}

void searchList(node *list)
{
    int item,flag=0;

    printf("Enter Search item: ");
    scanf("%d",&item);

    while(list->next!=0)
    {
        if(list->info==item)
        {
            flag++;
            printf("Search is Successful ");
            break;
        }
        list=list->next;
    }

    if(flag==0)
        printf("Search is unsuccessful");
}

int main()
{
    node n1;
    node *head;
    head=&n1;
    createList(head);
    printList(head);
//search

    searchList(head);

    return 0;
}
