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
    int item,flag=0,ctr=0;

    printf("Enter Search item: ");
    scanf("%d",&item);

    while(list->next!=0)
    {
        ctr++;
        if(list->info==item)
        {
            flag++;
            printf("Search is Successful ");
            break;
        }
        list=list->next;
    }
    printf("\nItem found at node no : %d ",ctr );

    if(flag==0)
        printf("Search is unsuccessful");



}
 node* insertFirst(node *list)
{
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode==0)
    {
        printf("\nOverflow Condition !!!");
        return 0;
    }
    else
    {
        printf("\nEnter Item to insert in the beginning  : ");
        scanf("%d",&newNode->info);
        newNode->next=list;
        list=newNode;

        return list;
    }

}

node* delete1(node *list)
{
    if(list==0)
    {
        printf("\nWe faced Underflow!!!");
        return 0;
    }
    else
    {
       list=list->next;
       return list;
    }
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
//insert at begaining
    head=insertFirst(head);
    printf("\nAfter Insertion ");
    printList(head);

//delete 1st node
    head=delete1(head);
    printf("\nAfter Delete ");
    printList(head);


    return 0;
}
