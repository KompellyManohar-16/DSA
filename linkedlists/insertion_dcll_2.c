#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else
    {
        newnode->prev=head->prev;
        newnode->next=head;
        head->prev->next=newnode;
        head->prev=newnode;
    }
    count++;
}

void insert_after(int data,int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty, no insertion");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allcation failed");
        return;
    }    
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    temp=head;
    do
    {
        if(temp->data==value)
        {
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next->prev=newnode;
            temp->next=newnode;
            count++;
            return;
        }
        temp=temp->next;
    } while (temp!=head);
    printf("\n the specified node is %d not found , no insertion",value);
    free(newnode);
}

void insert_before(int data, int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty, no insertion");
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
    newnode->prev=NULL;
    if(head!=NULL&&head->data==value)
    {
        newnode->next=head;
        newnode->prev=head->prev;
        head->prev->next=newnode;
        head->prev=newnode;
        head=newnode;
        count++;
        return;
    }
    temp=head;
    do
    {
        if(temp->data==value)
        {
            newnode->next=temp;
            newnode->prev=temp->prev;
            temp->prev->next=newnode;
            temp->prev=newnode;
            count++;
            return;
        }
        temp=temp->next;
    } while(temp!=head);
    printf("\n the specified node %d is not found , no insertion",value);
    free(newnode);
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
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %p\t<--\t%d\t-->\t%p",temp->prev,temp->data,temp->next);
        temp=temp->next;
    } while (temp!=head);
    
}

void freelist()
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
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
    printf("\n the list is freed");
}


int main()
{
    int data,choice,value;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. insert after the node");
        printf("\n 3. insert before the node");
        printf("\n 4. display");
        printf("\n 5. freelist");
        printf("\n 6. exit");
        printf("\n enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : printf("\n enter the data and the value : ");
                        scanf("%d %d",&data,&value);
                        insert_after(data,value);
                        break;
            case 3  : printf("\n enter the data and the value : ");
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