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

    printf("\n Post")
    return 0;
}