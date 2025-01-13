#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *root=NULL;

int get_height(struct node *node);
int max(int a, int b);
int get_balance_factor(struct node *root);
struct node *insert(struct node *root, int data);
struct node *right_rotation(struct node *x);
struct node *left_rotation(struct node *x);
struct node *delete_element(struct node *root, int data);
struct node *min(struct node *root);
void print_PreOrder(struct node *root);
void free_tree(struct node *root);
void print_InOrder(struct node *root);


int get_height(struct node *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->height;
}


int max(int a, int b)
{
    return a>b ? a : b;
}

int get_balance_factor(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return get_height(root->left) - get_height(root->right);
}

struct node *insert(struct node *root, int data)
{
    if(root == NULL)
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
        newnode->height=1;
        

        return newnode;
    }

    if(data < root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data > root->data)
    {
        root->right=insert(root->right,data);
    }
    else if(data == root->data)
    {
        return root;
    }

    root->height = 1 + max(get_height(root->left),get_height(root->right));

    int balance_factor=get_balance_factor(root);

    if(balance_factor > 1 && data < root->left->data)
    {
        return right_rotation(root);
    }
    else if(balance_factor > 1 && data > root->left->data)
    {
        root->left=left_rotation(root->left);
        return right_rotation(root);
    }
    else if(balance_factor < -1 && data > root->right->data)
    {
        return left_rotation(root);
    }
    else if(balance_factor < -1 && data < root->right->data)
    {
        root->right=right_rotation(root->right);
        return left_rotation(root);
    }

    return root;
}

struct node *right_rotation(struct node *x)
{
    struct node *y = x->left;
    struct node *p = y->right;

    y->right = x;
    x->left = p;

    x->height = 1 + max( get_height(x->left), get_height(x->right) );
    y->height = 1 + max( get_height(y->left), get_height(y->right) );  

    return y; 
}

struct node *left_rotation(struct node *x)
{
    struct node *y = x->right;
    struct node *p = y->left;

    y->left = x;
    x->right = p;

    x->height = 1 + max( get_height(x->left), get_height(x->right) );
    y->height = 1 + max( get_height(y->left), get_height(y->right) );

    return y;

}

struct node *delete_element(struct node *root, int data)
{
    if(root==NULL)
    {
        printf("\n The element %d is not found in the tree",data);
        return root;
    }
    if(data < root->data)
    {
        root->left = delete_element(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = delete_element(root->right,data);
    }
    else if(root->left==NULL && root->right==NULL)
    {
        free(root);
        printf("\n The element %d is deleted",data);
        return NULL;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        struct node *temp=root->right;
        free(root);
        printf("\n The element %d is deleted",data);
        return temp;
    }
    else if(root->right==NULL && root->left!=NULL)
    {
        struct node *temp=root->left;
        free(root);
        printf("\n The element %d is deleted",data);
        return temp;
    }
    else
    {
        struct node *Inorder_succesor=min(root->right);
        root->data = Inorder_succesor->data;
        printf("\n The element %d is replaced with it's Inorder successor %d",data,Inorder_succesor->data);
        root->right=delete_element(root->right,Inorder_succesor->data);

    }

    if(root==NULL)
    {
        return NULL;
    }

    root->height = 1 + max( get_height(root->left), get_height(root->right) );

    int balance_factor = get_balance_factor(root);

    if(balance_factor > 1 && get_balance_factor(root->left) >= 0)
    {
        return right_rotation(root);
    }
    else if(balance_factor > 1 && get_balance_factor(root->left) < 0)
    {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }
    else if(balance_factor < -1 && get_balance_factor(root->right) <= 0)
    {
        return left_rotation(root);
    }
    else if(balance_factor < -1 && get_balance_factor(root->right) > 0)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
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

    printf("\n\n Address : %p | Data : %d | Height : %d | Left : %p | Right : %p", root, root->data, root->height, root->left, root->right);
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
    printf("\n\n Address : %p | Data : %d | Height : %d | Left : %p | Right : %p", root, root->data, root->height, root->left, root->right);
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
    int choice,data,del;
    while(1)
    {
        printf("\n\n 1. insert");
        printf("\n 2. delete");
        printf("\n 3. Pre-Order");
        printf("\n 4. In-Order");
        printf("\n 5. free the tree");
        printf("\n 6. exit");
        printf("\n enter your choice : ");

        if((scanf("%d",&choice)!=1))
        {
            printf("\n Invalid data...exiting..!");
            free_tree(root);
            exit(EXIT_FAILURE);
        }
        switch(choice)
        {
            case 1  : printf("\n enter the data to insert : ");
                        scanf("%d",&data);
                        root=insert(root,data);
                        break;

            case 2  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            printf("\n enter the data : ");
                            scanf("%d",&del);
                            root=delete_element(root,del);
                        }
                        break;

            case 3  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            printf("\n The Pre-Order traversal is : ");
                            print_PreOrder(root);
                        }
                        break;

            case 4  : if(root==NULL)
                        {
                            printf("\n The tree is empty");
                        }
                        else
                        {
                            printf("\n The InOrder traversal is : ");
                            print_InOrder(root);
                        }
                        break;

            case 5  : free_tree(root);
                        root=NULL;
                        printf("\n The tree is freed");
                        break;

            case 6  : free_tree(root);
                        exit(EXIT_SUCCESS);

            default : printf("\n Invalid choice");
        }
    }
    return 0;
}
