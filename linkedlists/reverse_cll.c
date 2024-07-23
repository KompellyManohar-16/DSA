#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;
struct node *newnode=NULL;

int count=0;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n the memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    count++;
}

void reverse()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    struct node *prev=NULL;
    struct node *current=NULL;
    struct node *nextnode=NULL;
    struct node *end=head;
    while(end->next!=head)
    {
        end=end->next;
    }
    prev=end;
    current=head;
    do
    {
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    } while (current!=head);
    head=prev;
}

void display()
{
    if(head==NULL)
    {
        printf("\n the head is : %p",head);
        printf("\n the list is empty");
        return;
    }
    printf("\n the nodes are : ");
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %d\t-->\t%p",temp->data,temp->next);
        temp=temp->next;
    }while(temp!=head);
}

int main()
{
    int data,choice;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. reverse");
        printf("\n 3. display");
        printf("\n 4. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : reverse();
                        printf("\n the list is reversed");
                        break;
            case 3  : display();
                        break;
            case 4  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
}