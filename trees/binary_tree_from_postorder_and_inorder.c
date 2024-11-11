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


// 1. search the data in the inorder list from the given portion i.e from starting index ending index
// 2. if the data is found then return its index
// 3. after completing the for loop, if the data is not found then return -1


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

// * we first build the right sub tree then left sub tree because we are using post_order & in_order traversal
// * In post_order traversal the last element is the root of the binary tree. That's why we are scanning the post_order from right to left.

// 1. checking if(start > end):- it indicates invalid range creating nodes such as when we try to build a left or right children for a leaf node.
// 2. in the current variable we are storing the root from the post_order array
// 3. decrementing the post_index for further nodes
// 4. creating new node for the current data
// 5. if(start==end) :- indicates that the newnode is leaf node... if it is then return the newnode
// 6. identifying the index value in in_order list :- divides the in_order array into left sub-tree elements and right sub-tree elements
// 7. calling the function again for right sub tree using right portion elements
// 8. calling the funcion again for left sub tree using left portion elements
// 9. return the newnode


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


// 1. if root == NULL then return
// 2. print the left node
// 3. print the root node
// 4. print the right node 

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

// 1. if root == NULL then return
// 2. print the left node
// 3. print the right node
// 4. print the root node

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


// 1. if root == NULL then return
// 2. free the left node
// 3. free the right node
// 4. free the root node

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

// step 1 : take postorder and inorder traversal as inputs from the user
// step 2 : display the postorder and inorder traversal 
// step 3 : now initialize the post_index = n-1 for accessing the post_order array
// step 4 : now call the build tree 
// step 5 : call post-order traversal function
// step 6 : call in-order traversal function
// step 7 : call free_tree function

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