#include<iostream>
using namespace std;

class LinkedList
{
   public:
    char info;
    class LinkedList *next;
};
typedef class LinkedList node;

void createList(node *list)
{
    cout<<"Enter a item:(/ to exit):";
    cin>>list->info;

    if(list->info=='/')
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
    int ctr=0;
    cout<<"\n\nUpper case value of the List's contain :";
    while(list->next!=0)
    {
        ctr++;
        cout<<toupper(list->info);
        cout<<" ";
        list=list->next;
    }
    cout<<"\nNode count  : "<<ctr<<endl;
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
