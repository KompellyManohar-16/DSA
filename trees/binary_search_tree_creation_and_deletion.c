#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;

struct node *min(struct node *root);


struct node *insert(struct node *root, int data)
{

    if(root==NULL)
    {
        struct node *newnode=NULL;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("\n memory allocation failed");
            exit(EXIT_FAILURE);
        }

        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;

        return newnode;
    }

    

    if(data < root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }

    return root;
}

struct node *delete(struct node *root, int data)
{
    if(root==NULL)
    {
        printf("\n The given data %d is not found in the binary search tree",data);
        return root; // Here root is NULL 
    }
    if(data < root->data)
    {
        root->left=delete(root->left,data);
    }
    else if(data > root->data)
    {
        root->right=delete(root->right,data);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            printf("\n The deleted element is : %d",data);
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            struct node *temp=root->right;
            free(root);
            printf("\n The deleted elements is : %d",data);
            return temp;
        }
        else if(root->right==NULL && root->left!=NULL)
        {
            struct node *temp=root->left;
            free(root);
            printf("\n The deleted element is : %d",data);
            return temp;
        }
        else
        {
            struct node *InOrder_successor=min(root->right);

            root->data = InOrder_successor->data;

            printf("\n The element %d is replaced with it's inorder successor %d",data,InOrder_successor->data);

            root->right=delete(root->right, InOrder_successor->data);
        }
    }
    return root;
}

struct node *min(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}



void print_PreOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    printf("\n\n Address : %p | Data : %d | Left : %p | Right : %p",root, root->data, root->left, root->right);
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
    printf("\n\n Address : %p | Data : %d | Left : %p | Right : %p",root, root->data, root->left, root->right);
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
    printf("\n\n Address : %p | Data : %d | Left :%p | Right : %p",root, root->data, root->left, root->right);
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
    int choice,data,del;
    while(1)
    {
        printf("\n\n 1. insertion");
        printf("\n 2. deletion");
        printf("\n 3. pre-order traversal");
        printf("\n 4. in-order traversal");
        printf("\n 5. post-order traversal");
        printf("\n 6. free tree");
        printf("\n 7. exit");
        printf("\n enter your choice : ");

        if(scanf("%d",&choice)!=1)
        {
            printf("\n Invalid data.. exiting..!");
            free_tree(root);
            exit(EXIT_FAILURE);
        }       

        switch (choice)
        {

            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        root=insert(root,data);
                        break;

            case 2  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            printf("\n enter the key to delete : ");
                            scanf("%d",&del);
                            root=delete(root,del);
                        }
                        break;

            case 3  : if(root==NULL)
                        {
                            printf("\n\n The tree is empty");
                        }
                        else
                        {
                            printf("\n The Pre-Order Traversal is : ");
                            print_PreOrder(root);
                        }
                        break;

            case 4  : if(root==NULL)
                        {
                            printf("\n\n The tree is empty");
                        }
                        else
                        {
                            printf("\n The In-Order Traversal is : ");
                            print_InOrder(root);
                        }
                        break;

            case 5  : if(root==NULL)
                        {
                            printf("\n\n The tree is empty");
                        }
                        else
                        {
                            printf("\n The Post-Order Traversal is : ");
                            print_PostOrder(root);
                        }
                        break;
            
            case 6  : if(root==NULL)
                        {
                            printf("\n\n The tree is empty");
                        }
                        else
                        {
                            free_tree(root);
                            root=NULL;
                            printf("\n The tree is freed");
                        }
                        break;

            case 7  : free_tree(root);
                        printf("\n exiting... !");
                        root=NULL;
                        exit(EXIT_FAILURE); 

            default: printf("\n Invalid choice");
        }
    }
    return 0;
}