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
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
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
    }
    count++;
}

void insert_after(int data,int value)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            newnode->next=temp->next;
            temp->next=newnode;
            count++;
            return;
        }
        temp=temp->next;
    }
        printf("\n the node value %d is not found , no insertion",value);
        free(newnode);
}

void insert_before(int data,int value)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;

    if(head!=NULL&&head->data==value)
    {
        newnode->next=head;
        head=newnode;
        count++;
        return;
    }
    struct node *prev=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            newnode->next=temp;    
            prev->next=newnode;
            count++;
            return;
        }
            prev=temp;
            temp=temp->next;
    } 
        printf("\n the node value %d is not found , no insertion",value);
        free(newnode);
}

void display()
{
    if(head==NULL)
    {
        printf("\n List is empty");
        printf("\n the head is : %p",head);
        return;
    }
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

void freelist()
{
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
        count--;
    }
}


int main()
{
    int choice,data,value;
    while(1)
    {
        printf("\n 1.insert");
        printf("\n 2.insert after a given node");
        printf("\n 3.insert before a given node");
        printf("\n 4.display");
        printf("\n 5.free list");
        printf("\n 6.exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : printf("\n enter the data and value : ");
                        scanf("%d %d",&data,&value);
                        insert_after(data,value);
                        break;
            case 3  : printf("\n enter the data and value : ");
                        scanf("%d %d",&data,&value);
                        insert_before(data,value);
                        break;
            case 4  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 5  : freelist();
                        printf("\n the list is freed");
                        break;
            case 6  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}