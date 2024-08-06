#include<stdio.h> 
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *top=NULL;
struct node *newnode=NULL;
struct node *temp=NULL;

void push(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}


void pop()
{
    if(top==NULL)
    {
        printf("\n the stack is empty");
    }
    else
    {
        temp=top;
        top=top->next;
        printf("\n the deleted element is : %d",temp->data);
        free(temp);
    }
}


void peek()
{
    if(top==NULL)
    {
        printf("\n the stack is empty");
    }
    else
    {
        printf("\n the topmost element is : %d",top->data);
    }
}


void display()
{
    int count=0;
    printf("\n the top is : %p",top);
    if(top==NULL)
    {
        printf("\n the stack is empty");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("\n %d\t-->\t%p",temp->data,temp->next);
            temp=temp->next;
            count++;
        }
    }
    printf("\n the total no.of elements are : %d",count);
}

void free_stack()
{
    if(top==NULL)
    {
        printf("\n the stack is already empty");
    }
    else
    {
        while(top!=NULL)
        {
            temp=top;
            top=top->next;
            free(temp);
        }
        printf("\n the stack is freed");
    }
}


int main()
{
    int data,choice;
    while(1)
    {
        printf("\n\n 1. push");
        printf("\n 2. pop");
        printf("\n 3. peek");
        printf("\n 4. display");
        printf("\n 5. free_stack");
        printf("\n 6. exit");
        printf("\n enter your choice : ");
        if(scanf("%d",&choice)!=1)
        {
            printf("\n Invalid input.Please enter the a number");
            while(getchar()!='\n');
            continue;
        }
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        if(scanf("%d",&data)!=1)
                        {
                            printf("\n Invalid input.Please enter a number");
                            while(getchar()!='\n');
                            continue;
                        }
                        push(data);
                        break;
            case 2  : pop();
                        break;
            case 3  : peek();
                        break;
            case 4  : display();
                        break;
            case 5  : free_stack();
                        break;
            case 6  : return 0;
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}