#include<iostream>
using namespace std;

class LinkedList
{
   public:
    int info;
    class LinkedList *next;
};
typedef class LinkedList node;
int siz = 0;
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
        siz++;
    }

}
void printList(node *list)
{
    int sum=0,ctr;
    cout<<"\nList Contains : ";
    while(list->next!=0)
    {
        cout<<list->info<<" ";
        sum=sum+list->info;
//        if(list->next->next==0)
//            printf("%d ",list->next->info);
        list=list->next;
    }
    cout<<endl<<"The sum is "<<sum<<endl;
    cout<<"Node count  : "<<siz<<endl;
}
void searchList(node *list)
{
     int item,flag=0;

    cout<<"Enter Search item: ";
    cin>>item;

    while(list->next!=0)
    {
        if(list->info==item)
        {
            flag++;
            cout<<"Search is Successful ";
            break;
        }
        list=list->next;
    }

    if(flag==0)
        cout<<"Search is unsuccessful";
}

 node* insertFirst(node *list)
{
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode==0)
    {
        cout<<"\nOverflow Condition !!!";
        return 0;
    }
    else
    {
        cout<<"\nEnter Item to insert in the beginning  : ";
        cin>>newNode->info;
        newNode->next=list;
        list=newNode;
        siz++;
        return list;
    }

}

node* delete1(node *list)
{
    if(list==0)
    {
        cout<<"\nWe faced Underflow!!!";
        return 0;
    }
    else
    {
        siz--;
       list=list->next;
       return list;
    }

}

void insertPos(node** current, int pos, int data)
{
    if (pos < 1 || pos > siz + 1)
        cout << "Invalid position!" << endl;
    else {
        while (pos--) {
            if (pos == 0) {
                node *newNode = (node*)malloc(sizeof(node));
                newNode->info = data;
                newNode->next = *current;
                *current = newNode;
            }
            else
              current = &(*current)->next;
        }
        siz++;
    }
}

void deleteNode(node **head_ref, int position)
{
   if (*head_ref == NULL)
      {
          cout<<"\nUnderflow"<<endl;
      }

    node* temp = *head_ref;

    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    if (temp == NULL || temp->next == NULL)
         return;


    node *next = temp->next->next;


    free(temp->next);

    temp->next = next;
    siz--;
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

//insert at first
    head=insertFirst(head);
    cout<<"\nAfter Insertion ";
    printList(head);

//delete 1st node
    head=delete1(head);
    cout<<"\nAfter Delete ";
    printList(head);

    int data = 12, pos = 3;
    insertPos(&head, pos, data);
    cout << "\nLinked list after insertion of 12 at position 3: ";
    printList(head);

    deleteNode(&head, 4);
    cout<<"\nLinked List after Deletion at position 4: ";
    printList(head);
    return 0;
}
