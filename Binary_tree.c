#include <stdio.h>
#include <stdlib.h>
struct BinaryTree
{
    int info;
    struct BinaryTree *left;
    struct BinaryTree *right;
};
typedef struct BinaryTree node;

node *Create_Tree()
{
    int x;
    printf("\n Enter a number(-1 for no node)");
    scanf("%d",&x);
    if(x==-1)
        return 0;

    node *p;
    p=(node*)malloc(sizeof(node));
    p->info=x;

    printf("\nEnter the left child of %d ",x);

    p->left=Create_Tree();

    printf("\nEnter the right child of %d ",x);

    p->right=Create_Tree();

    return p;
}
void postorder_traversing(node *r)
{

    if (r!=NULL)
    {
    postorder_traversing(r->left);
    postorder_traversing(r->right);
    printf ("%d ", r->info);
    }


}
void inorder(node *r)
{

    if (r!=NULL)
    {
    inorder(r->left);
    printf ("%d ", r->info);
    inorder(r->right);

    }
}
int main()
{
    node *root;
    root=Create_Tree();
    printf("Postorder Traversing is :\n");

    postorder_traversing(root);
    printf("Inorder Traversing is :\n");
    inorder(root);
    return 0;
}
