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

struct node *find_min(struct node *root);

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


struct node * build_tree(int pre_order[], int start, int end, int *pre_index, int n)
{

    if(start > end || *pre_index>=n)
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


struct node * delete_key(struct node * root, int key)
{
    if(root==NULL)
    {
        printf("\n the key %d is not found in the binary search tree",key);
        return NULL;
    }

    if(key < root->data)
    {
        root->left=delete_key(root->left,key);
    }
    else if(key > root->data)
    {
        root->right=delete_key(root->right,key);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            printf("\n The element %d is deleted",key);
            return NULL;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root->right;

            free(root);
            printf("\n The element %d is deleted",key);
           
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;

            free(root);
            printf("\n The element %d is deleted",key);

            return temp;
        }
        else
        {
            struct node *temp=find_min(root->right);

            root->data=temp->data;
            printf("\n the key %d is replaced with it's in-order successor %d",key,temp->data);
            root->right=delete_key(root->right,temp->data);

        }
    }

    return root;
}

struct node *find_min(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
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
    int choice;
   while(1)
    {
        printf("\n\n 1. create binary search tree");
        printf("\n 2. pre-order traversal");
        printf("\n 3. in-order traversal");
        printf("\n 4. deletion");
        printf("\n 5. free tree");
        printf("\n 6. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  :     
            {
                            if(root!=NULL)
                            {
                                printf("\n a tree is already existing.. freeing the tree before creating a new one");
                                free_tree(root);
                                root=NULL;
                            }

                            int pre_order[MAX];
                            int n;
                            printf("\n enter the no.of nodes in the binary search tree :");
                            scanf("%d",&n);

                            if(n<=0 || n>MAX)
                            {
                                printf("\n Invalid no of nodes.. please enter a valid value between 1 and %d ",MAX);
                                break;
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

                            root=build_tree(pre_order,0,n-1,&pre_index,n);
                            break;
            }
            case 2  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                             printf("\n\n The pre-order traversal is : ");
                            print_PreOrder(root);
                        }
                        break;

            case 3  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            printf("\n\n The in-order traversal is : ");
                            print_InOrder(root);
                        }
                        break;
                        
            case 4  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            int key;
                            printf("\n enter the key to delete :");
                            scanf("%d",&key);
                            root=delete_key(root,key);
                        }
                        break;

            case 5  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            free_tree(root);
                            root=NULL;
                            printf("\n the tree is freed");
                        }
                        break;

            case 6  :   free_tree(root);
                        printf("\n exiting...!");
                        return 0;

            default : printf("\n Invalid choice");
        }
    }
    return 0;
}