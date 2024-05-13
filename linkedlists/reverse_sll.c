#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *newnode=NULL;
struct node *temp=NULL;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(newnode==NULL)
    {
        printf("\n memory allocation is failed");
    }
    else
    {
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }     
    }
}

void reverse()
{
    struct node *prevnode, *current, *nextnode;
    prevnode=NULL;
    current=head;
    nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        current->next=prevnode;
        prevnode=current;
        current=nextnode;
    }
    head=prevnode;
}

void display()
{
    temp=head;
    printf("\n the nodes are : ");
    printf("\n the data \t --> \t the address");
    printf("\n the head is : %p",head);
    while(temp!=NULL)
    {
         printf("\n %d \t --> \t %p",temp->data,temp->next);
         temp=temp->next;
    }
}




int main()
{
    int choice,count=0,data;
    while(1)
    {
        printf("\n 1.insertion");
        printf("\n 2.reverse");
        printf("\n 3.display");
        printf("\n 4.exit");    
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data to insert : ");
                        scanf("%d",&data);
                        insert(data);
                        count++;
                        break;
            case 2  : reverse();
                        printf("\n the list is reversed");
                        break;
            case 3  : display();
                        printf("\n the no.of nodes are : %d",count);
                        break;
            case 4  : exit(0);
            default : printf("\n invalid choice");
        }
    }
    return 0;
}