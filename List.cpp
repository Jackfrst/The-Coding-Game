#include <iostream>
#include <stdlib.h>
using namespace std;

class Linked_List
{
public:
    int data;
    class Linked_List *next;
};

typedef class Linked_List node;

void createList(node *list)
{
    cout<<"Enter a data:(-1 to exit) ";
    cin>>list->data;

    if(list->data==-1)
        list->next=0;
    else
    {
        node *newnode;

        newnode=(node*)malloc(sizeof(node));
        list->next=newnode;
        createList(newnode);
    }
}

int main()
{
    node *start;
    start=(node*) malloc(sizeof(node));
    createList(start);
    return 0;
}
