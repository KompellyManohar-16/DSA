#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root= NULL;

int search(int post_order[], int start, int end, int data)
{
    for(int i=start;i<=end;i++)
    {
        if(data==post_order[i])
        {
            return i;
        }
    }
    return -1;
}

struct node * build_tree(int pre_order[], int post_order[], int start, int end, int * pre_index,int n)
{
    if(start > end || *pre_index >= n)
    {
        return NULL;
    }
    
    int current=pre_order[*pre_index];
    (*pre_index)++;

    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newnode->data=current;
    newnode->left=NULL;
    newnode->right=NULL;

    if(start == end || *pre_index >= n)
    {
        return newnode;
    }

    int successor=pre_order[*pre_index];
    int post_index=search(post_order,start,end,successor);
    if(post_index==-1)
    {
        printf("\n Inconsistent data %d is not found in the post_order traversal",successor);
        exit(EXIT_FAILURE);
    }

    newnode->left=build_tree(pre_order,post_order,start,post_index,pre_index,n);

    newnode->right=build_tree(pre_order,post_order,post_index+1,end-1,pre_index,n);

    return newnode;
}

void print_PreOrder(struct node * root)
{
    if(root==NULL)
    {
        return;
    }
    printf("\n\n %p",root);
    printf("\n %p <-- %d --> %p",root->left,root->data,root->right);
    print_PreOrder(root->left);
    print_PreOrder(root->right);
}

void print_PostOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    print_PostOrder(root->left);
    print_PostOrder(root->right);

    printf("\n\n %p",root);
    printf("\n %p <-- %d --> %p",root->left,root->data,root->right);
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
    int pre_order[MAX],post_order[MAX],n;

    printf("\n enter the no.of nodes in the full binary tree : ");
    if(scanf("%d",&n)!=1 || n<0)
    {
        printf("\n Invalid input... exiting!!!");
        return 0;
    }
    if(n==0)
    {
        printf("\n The full binary tree is empty");
        return 0;
    }

    printf("\n enter the pre_order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pre_order[i]);
    }
    printf("\n enter the post_order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post_order[i]);
    }

    printf("\n The pre_order traversal entered is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",pre_order[i]);
    }
    printf("\n The post_order traversal entered is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",post_order[i]);
    }

    int pre_index=0;

    root=build_tree(pre_order,post_order,0,n-1,&pre_index,n);


    printf("\n\n The pre-order traversal for the constructed tree is : ");
    print_PreOrder(root);

    printf("\n\n The post-order traversal for the constructed tree is : ");
    print_PostOrder(root);


    free_tree(root);
    root=NULL;




    return 0;

}