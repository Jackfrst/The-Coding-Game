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
    cout<<"\nList Contains:";
    while(list->next!=0)
    {
        ctr++;
        cout<<list->info<<" ";
        list=list->next;
    }
    cout<<"\nNode count  : "<<ctr;
}

void searchList(node *list)
{
     int item,flag=0,pos=0;

    cout<<"\nEnter Search item: ";
    cin>>item;

    while(list->next!=0)
    {
        if(list->info==item)
        {
            flag++;
            cout<<"\nSearch is Successful \n";
            cout<<"Item found at node no "<<pos<<endl<<endl;
            break;
        }
        pos++;
        list=list->next;
    }

    if(flag==0)
        cout<<"\nSearch is unsuccessful";

}

int main()
{
    node n1;
    node *head;
    head=&n1;

    cout<<"Enter a shorted link list : "<<endl<<endl;
    createList(head);
    printList(head);
    searchList(head);

    return 0;
}


