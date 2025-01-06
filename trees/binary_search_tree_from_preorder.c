#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;

int max(int pre_order[],int start, int end, int data)
{
    for(int i=start;i<=end;i++)
    {
        printf("\n Checking if %d > %d" ,pre_order[i],data);
        if(pre_order[i] > data)
        {
            return i;
        }
    }
    return -1;
}


struct node * build_tree(int pre_order[], int start, int end, int *pre_index)
{

    if(start > end)
    {
        return NULL;
    }
    
    int current=pre_order[*pre_index];
    (*pre_index)++;

    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newnode->data=current;
    newnode->left=NULL;
    newnode->right=NULL;

    if(start==end)
    {
        return newnode;
    }

    int first_greater_element=max(pre_order,start,end,current);

    if(first_greater_element==-1)
    {
        newnode->right=NULL;
        newnode->left=build_tree(pre_order,start+1,end,pre_index);
        return newnode;
    }

    newnode->left=build_tree(pre_order,start+1,first_greater_element-1,pre_index);
    newnode->right=build_tree(pre_order,first_greater_element,end,pre_index);

    return newnode;

}

void print_PreOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    printf("\n\nNode Address: %p | Data: %d | Left: %p | Right: %p", root, root->data, root->left, root->right);

    print_PreOrder(root->left);
    print_PreOrder(root->right);
}


void print_InOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    print_InOrder(root->left);

    printf("\n\nNode Address: %p | Data: %d | Left: %p | Right: %p", root, root->data, root->left, root->right);

    print_InOrder(root->right);
}

void free_tree(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);

}


int main()
{
    int pre_order[MAX];
    int n;
    printf("\n enter the no.of nodes in the binary search tree :");
    scanf("%d",&n);

    if(n<=0 || n>MAX)
    {
        printf("\n Invalid no of nodes");
        return 0;
    }

    printf("\n enter the pre_order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pre_order[i]);
    }
    printf("\n The pre_order traversal is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",pre_order[i]);
    }

    int pre_index=0;

    root=build_tree(pre_order,0,n-1,&pre_index);

    printf("\n\n The pre-order traversal is : ");
    print_PreOrder(root);

    printf("\n\n The in-order traversal is : ");
    print_InOrder(root);

    free_tree(root);
    root=NULL;

    return 0;
}