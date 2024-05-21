#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
struct node* newnode=NULL;
struct node* temp=NULL;

int count=0;


void insert_at_begin(int data)
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
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    count++;    
}

void insert_at_end(int data)
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

void insert_at_specific(int data,int pos)
{
    if(pos<1||pos>count+1)
    {
        printf(" INVALID POSITION");
        return;
    }
    if(pos==1)
    {
        insert_at_begin(data);
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
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL)
    {
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    count++;      
}

void insert_at_after_pos(int data,int pos)
{
    if(pos<1||pos>count)
    {
        printf("\n INVALID POSITION");
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
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL)
    {
       temp->next->prev=newnode;
    }
    temp->next=newnode;
    count++;
}

void insert_at_before_pos(int data,int pos)
{
    if(pos<1||pos>count+1)
    {
        printf("\n Invalid position");
        return;
    }
    if(pos==1)
    {
        insert_at_begin(data);
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
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL)
    {
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    count++;
}


void display()
{
    if(head==NULL)
    {
        printf("\n List is empty");
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

int main()
{
    int choice,data,pos;
    while(1)
    {
        printf("\n 1. insertion at begin");
        printf("\n 2. insertion at end");
        printf("\n 3. insert at a specific position");
        printf("\n 4. insert after a given position");
        printf("\n 5. insert before a given position");
        printf("\n 6. display");
        printf("\n 7. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert_at_begin(data);
                        break;
            case 2  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert_at_end(data);
                        break;
            case 3  : printf("\n enter the data and pos : ");
                        scanf("%d %d",&data,&pos);
                        insert_at_specific(data,pos);
                        break;
            case 4  : printf("\n enter the data and pos : ");
                        scanf("%d %d",&data,&pos);
                        insert_at_after_pos(data,pos);
                        break;
            case 5  : printf("\n enter the data and pos :");
                        scanf("%d %d",&data,&pos);
                        insert_at_before_pos(data,pos);
                        break;
            case 6  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 7  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}