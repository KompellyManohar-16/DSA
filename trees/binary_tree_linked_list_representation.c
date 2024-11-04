#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
int count=0;


struct node * create()
{
    int data;
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return NULL;
    }

    printf("\n enter the node value (Use -1 for NULL): ");
    scanf("%d",&data);   

    if(data==-1)
    {
        free(newnode);
        return NULL;
    }

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;


    count++;    
   

    printf("\n enter the Left Child for %d which is at %p : ",newnode->data,newnode);
    newnode->left=create();
    printf("\n enter the Right Child for %d which is at %p: ",newnode->data,newnode);
    newnode->right=create();
    return newnode;
}

void pre_order(struct node * root)
{
    if(root==NULL)
    {
        return;
    }
    printf("\n\n%p",root);
    printf("\n%p \t <-- \t %d \t --> \t %p",root->left,root->data,root->right);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    in_order(root->left);
    printf("\n\n %p",root);
    printf("\n %p \t <-- \t %d \t --> \t %p",root->left,root->data,root->right);
    in_order(root->right);
}

void post_order(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("\n\n %p",root);
    printf("\n %p \t <-- \t %d \t --> \t %p",root->left,root->data,root->right);
}

void free_tree(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);

    printf("\n the deleted nodes is : %p <-- %d --> %p",root->left,root->data,root->right);
    free(root);
}


int main()
{
    int choice;
    while(1)
    {
        printf("\n\n 1. create");
        printf("\n 2. pre-order");
        printf("\n 3. in-order");
        printf("\n 4. post-order");
        printf("\n 5. free memory");
        printf("\n 6. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : root=create();
                        break;
            case 2  : printf("\n the root is : %p",root);
                        if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            pre_order(root);
                        }
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 3  :  printf("\n the root is : %p",root);
                        if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            in_order(root);
                        }
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 4  : printf("\n the root is : %p",root);
                        if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            post_order(root);
                        }
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 5  :   if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            free_tree(root);
                            root=NULL;
                            count=0;
                            printf("\n The tree is freed");
                        }
                        break;
            case 6  : printf("\n exiting...");
                        return 0;
            default : printf("\n INVALID CHOICE");
        }
    }
    return 0;
}