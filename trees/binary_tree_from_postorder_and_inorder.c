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


int search(int in_order[], int start, int end, int data)
{
    for(int i=start; i<=end; i++)
    {
        if(in_order[i]==data)
        {
            return i;
        }
    }
    return -1;
}

struct node *build_tree(int post_order[], int in_order[], int start, int end, int *post_index)
{
    if(start>end)
    {
        return NULL;
    }


    int current=post_order[*post_index];
    (*post_index)--;


    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return NULL;
    }
    newnode->data=current;
    newnode->right=NULL;
    newnode->left=NULL;

    if(start==end)
    {
        return newnode;
    }

    int in_index=search(in_order,start,end,current);
    if(in_index==-1)
    {
        printf("\n Inconsistent data, %d is not found in the in-order list",current);
        exit(EXIT_FAILURE);
    }

    newnode->right=build_tree(post_order,in_order,in_index+1,end,post_index);
    newnode->left=build_tree(post_order,in_order,start,in_index-1,post_index);

    return newnode;
                                                    
}

void print_InOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    print_InOrder(root->left);

    printf("\n\n %p",root);
    printf("\n %p <-- %d --> %p ",root->left,root->data,root->right);

    print_InOrder(root->right);
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
    printf("\n %p <-- %d --> %p",root->left, root->data, root->right);

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
    int post_order[MAX], in_order[MAX];
    int n;

    printf("\n enter the no.of nodes in the tree : \n");
    scanf("%d",&n);

    if(n==0)
    {
        printf("\n The tree is empty");
        return 0;
    }

    printf("\n enter the post-order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post_order[i]);
    }
    printf("\n enter the in-order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in_order[i]);
    }

    printf("\n The post-order traversal is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",post_order[i]);
    }
    printf("\n The in-order traversal is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",in_order[i]);
    }


    int post_index=n-1;


    root=build_tree(post_order,in_order,0,n-1, &post_index);

    printf("\n\n Post-order traversal : ");
    print_PostOrder(root);

    printf("\n\n In-order traversal : ");
    print_InOrder(root);

    free_tree(root);
    root=NULL;

    return 0;
}