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

int min(int post_order[], int start, int end, int data)
{
    for(int i=end;i>=start;i--)
    {
        if(post_order[i] < data)
        {
            return i;
        }
    }
    return -1;
}

struct node *build_tree(int post_order[], int start, int end, int *post_index)
{
    if(start > end || *post_index<0)
    {
        return NULL;
    }

    int current=post_order[*post_index];
    (*post_index)--;

    struct node * newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newnode->data=current;
    newnode->left=NULL;
    newnode->right=NULL;

    if(start == end)
    {
        return newnode;
    }

    int first_smallest_element=min(post_order,start,end,current);
    
    if(first_smallest_element==-1)
    {
        newnode->left=NULL;
        newnode->right=build_tree(post_order,start,end-1,post_index);
        return newnode;
    }

    newnode->right=build_tree(post_order,first_smallest_element+1, end-1, post_index);
    newnode->left=build_tree(post_order,start,first_smallest_element,post_index);

    return newnode;
}

void print_PostOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    print_PostOrder(root->left);
    print_PostOrder(root->right);
    printf("\n\n Node Address : %p | Data : %d | Left : %p | Right : %p",root,root->data,root->left,root->right);

}


void print_InOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    print_InOrder(root->left);
    printf("\n\n Node Address : %p | Data : %d | Left : %p | Right : %p",root,root->data,root->left,root->right);
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
    int post_order[MAX];
    int n;
    printf("\n enter the no.of nodes in binary search tree : ");
    scanf("%d",&n);

    if(n<=0 || n > MAX )
    {
        printf("\n Invalid input .... n is not in the range of 1 to %d",MAX);
        return 0;
    }

    printf("\n enter the post-order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post_order[i]);
    }

    printf("\n The post_order traversal is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",post_order[i]);
    }

    int post_index=n-1;

    root=build_tree(post_order,0,n-1,&post_index);

    printf("\n\n The Post-Order traversal is : ");
    print_PostOrder(root);

    printf("\n\n The InOrder traversal is : ");
    print_InOrder(root);

    free_tree(root);
    root=NULL;

    return 0;
}