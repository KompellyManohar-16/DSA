#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node  *prev;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;
struct node *newnode=NULL;

int count=0;

void insert_at_begin(int data)
{
    newnode=(struct node *)malloc(sizeof(struct node));
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
        newnode->next=head;
        newnode->prev=head->prev;
        head->prev->next=newnode;
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
        printf("\n the memory allocation failed");
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

void insert_at_specific_pos(int data,int pos)
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
    if (pos == count + 1)
    {
        insert_at_end(data);  
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
    temp->next->prev=newnode;
    temp->next=newnode;
    count++;
}

void insert_after_pos(int data, int pos)
{
    if(pos<1||pos>count)
    {
        printf("\n Invalid position");
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
    temp->next->prev=newnode;
    temp->next=newnode;
    count++;
}

void insert_before_pos(int data, int pos)
{
    if(pos<1||pos>count)
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
    temp->next->prev=newnode;
    temp->next=newnode;
    count++;
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
        printf("\n %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
        temp=temp->next;
    }while(temp!=head);
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
    } while (temp!=head);
    head=NULL;
    count=0;
    printf("\n all nodes are freed and the list is empty");
}

int main()
{
    int data,pos,choice;
    while(1)
    {
        printf("\n");
        printf("\n 1. insert at begin");
        printf("\n 2. insert at end");
        printf("\n 3. insert at specific position");
        printf("\n 4. insert after the position");
        printf("\n 5. insert before the position");
        printf("\n 6. display");
        printf("\n 7. freelist");
        printf("\n 8. exit");
        printf("\n enter the choice : ");
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
            case 3  : printf("\n enter the data and the position : ");
                        scanf("%d %d",&data,&pos);
                        insert_at_specific_pos(data,pos);
                        break;
            case 4  : printf("\n enter the data and the position : ");          
                        scanf("%d %d",&data,&pos);
                        insert_after_pos(data,pos);
                        break;
            case 5  : printf("\n enter the data and the position : ");
                        scanf("%d %d",&data,&pos);
                        insert_before_pos(data,pos);
                        break;
            case 6  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 7  : freelist();
                        break;
            case 8  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
}