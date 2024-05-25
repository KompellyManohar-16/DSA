#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *newnode=NULL;
struct node *temp=NULL;

int count=0;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
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
    struct node *nextnode=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            head=temp;
        }
        nextnode=temp->next;
        temp->next=temp->prev;
        temp->prev=nextnode;
        temp=nextnode;
    }
    printf("\n the double linked list is reversed");
}

void display()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        printf("\n the head is : %p",head);
        return;
    }
    printf("\n the nodes are : ");
    printf("\n the prev \t <-- \t the data \t --> \t the next");
    printf("\n the head is : %p",head);
    temp=head;
    while(temp!=NULL)
    {
        printf("\n %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
        temp=temp->next;
    }
}

void free_list()
{
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    head=NULL;
    count=0;
}

int main()
{
    int choice,data;
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
                        break;
            case 3  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 4  : free_list();
                        printf("\n Exiting....");
                        return 0;
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}

