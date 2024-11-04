#include<stdio.h> 
#include<stdlib.h>
#define MAX 101

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;


// 1. search the data in the in_order from the given portion i.e from starting index and ending index
// 2. if the data is found then return its index/location
// 3. after exiting from the for loop if the data is not found then return -1


int search(int in_order[],int start, int end, int data)
{
    for(int i=start;i<=end;i++)
    {
        if(in_order[i]==data)
        {
            return i;
        }
    }
    return -1;
}


// 1. checking if(start > end):- it indicates invalid range creating nodes such as when we try to build a left or right children for a leaf node.
// 2. in the current variabel we are storing the root from the pre_order array
// 3. incrementing the pre_index for further nodes
// 4. creating new node for the current data
// 5. if(start==end) :- indicates that the newnode is leaf node... if it is then return
// 6. identifying the index value in in_order list :- divides the in_order array into left sub-tree elements and right sub-tree elements
// 7. calling the function again for left sub tree using left portion elements
// 8. calling the funcion again for right sub tree using right portion elements
// 9. return the newnode 

struct node * build_tree(int pre_order[], int in_order[], int start, int end, int * pre_index)
{
    if(start>end)
    {
        return NULL;
    }



    int current=pre_order[*pre_index];
    (*pre_index)++;


    struct node * newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return NULL;
    }
    newnode->data=current;
    newnode->left=NULL;
    newnode->right=NULL;

    if(start==end)
    {
        return newnode;
    }


    int in_index=search(in_order,start,end,current);

    newnode->left=build_tree(pre_order, in_order, start, in_index-1, pre_index);
    newnode->right=build_tree(pre_order, in_order, in_index+1, end, pre_index);

    return newnode;
}


// 1. if root is NULL then return 
// 2. first print the root node
// 3. print the left node
// 4. print the right node

void print_PreOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("\n\n%p",root);
    printf("\n %p <-- %d --> %p",root->left,root->data,root->right);
    print_PreOrder(root->left);
    print_PreOrder(root->right);

}

// 1. if root is NULL then return 
// 2. first print the left node
// 3. print the root node
// 4. print the right node
void print_InOrder(struct node * root)
{
    if(root==NULL)
    {
        return;
    }

    print_InOrder(root->left);

    printf("\n\n %p",root);
    printf("\n %p <-- %d --> %p",root->left,root->data,root->right);
    
    print_InOrder(root->right);

}

// step 1 : take preorder and inorder traversal as inputs from the user
// step 2 : display the preorder and inorder traversal 
// step 3 : now initialize the pre_Index variable for accessing the pre_order array
// step 4 : now call the build tree 
// step 5 : call pre-order traversal function
// step 6 : call in-order traversal function


int main()
{
    int n;
    int pre_order[MAX],in_order[MAX];
    printf("\n enter the no.of nodes in the tree : ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("\n The tree is empty");
        return 0;
    }
    printf("\n enter the pre-order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pre_order[i]);
    }
    printf("\n enter the in-order traversal : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in_order[i]);
    }
    printf("\n the pre-order traversal is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",pre_order[i]);

    }
    printf("\n the in-order traversal is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",in_order[i]);
    }


    int pre_index=0;
    root=build_tree(pre_order, in_order, 0, n-1, &pre_index);

    printf("\n\n the pre-order traversal is : \n");
    print_PreOrder(root);

    printf("\n\n the in-order traversal is : \n");
    print_InOrder(root);

    return 0;
}