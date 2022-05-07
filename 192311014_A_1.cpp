#include<iostream>
using namespace std;

class LinkedList
{
   public:
    int info;
    class LinkedList *next;
};
typedef class LinkedList node;
void createList(node *list)
{
    cout<<"Enter a item:(-999 to exit):";
    cin>>list->info;

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
    int sum=0,ctr=0;
    cout<<"List Contains:";
    while(list->next!=0)
    {
        ctr++;
        cout<<list->info<<" ";
        if(list->info >= 0)
        {
            sum=sum+list->info;
        }

        list=list->next;
    }
    cout<<endl<<"\nThe sum of the positive numbers in the link list is :  "<<sum<<endl<<endl;
    cout<<"Node count  : "<<ctr;
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
