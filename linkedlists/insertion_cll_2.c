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
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;   
    }
    newnode->next=head;
    count++;
}

void insert_after(int data,int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty, no creation");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    temp=head;
    do
    {
        if(temp->data==value)
        {
            newnode->next=temp->next;
            temp->next=newnode;
            count++;
            return;
        }
        temp=temp->next;
    }while(temp!=head);
    printf("\n the given node is not found in the list, no insertion");
}

void insert_before(int data,int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty, no creation");
        return;
    }
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
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        head=newnode;
        temp->next=head;
        count++;
        return;
    }
    struct node*prevnode=NULL;
    temp=head;
    do
    {
        if(temp->data==value)
        {
            newnode->next=temp;
            prevnode->next=newnode;
            count++;
            return;
        }
        prevnode=temp;
        temp=temp->next;
    } while(temp!=head);
    printf("\n the given node is not found in the list , no insertion");
}

void display()
{
    if(head==NULL)
    {
        printf("\n the head is : %p",head);
        printf("\n the list is empty");
        return;
    }
    printf("\n the nodes are :");
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %d \t --> \t %p",temp->data,temp->next);
        temp=temp->next;
    } while(temp!=head);
}

void freelist()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
   struct node *nextnode;
   temp=head;
   do
   {
        nextnode=temp->next;
        free(temp);
        temp=nextnode;
   }while(temp!=head);
   head=NULL;
   count=0;
   printf("\n all the nodes are freed , the list is empty");
}




int main()
{
    int choice,data,value;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. insertion after a node");
        printf("\n 3. insertion before a node");
        printf("\n 4. display");
        printf("\n 5. freelist");
        printf("\n 6. exit");
        printf("\n enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data to insert : ");
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
                        break;
            case 6  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
}