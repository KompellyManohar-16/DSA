#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
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

void delete_at_begin()
{
    if(head==NULL)
    {
        printf("\n the list is empty , no deletion");
        return;
    }
    temp=head;
    if(head->next==head)
    {
        head=NULL;
    }
    else
    {
        struct node *last=head;
        while(last->next!=head)
        {
            last=last->next;
        }
        head=head->next;
        last->next=head;
    }
    printf("\n the deleted node is : %d \t --> \t %p",temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("\n the list is empty , no deletion");
        return;
    }
    temp=head;
    if(head->next==head)
    {
        head=NULL;
    }
    else
    {
        struct node *prev=NULL;
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
    }
    printf("\n the deleted node is : %d \t --> \t %p",temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_specific_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is empty, no deletion");
        return;
    }
    if(pos<1||pos>count)
    {
        printf("\n Invalid position");
        return;
    }
    if(pos==1)
    {
        delete_at_begin();
        return;
    }
    struct node*prev=NULL;
    temp=head;
    int i=1;
    while(i<pos)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    printf("\n the deleted node is : %d\t-->\t%p",temp->data,temp->next);
    free(temp);
    count--;
}

void delete_after_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is empty, no creation");
        return;
    }
    if(pos<1||pos>=count)
    {
        printf("\n Invalid position");
        return;
    }
    int i=1;
    struct node *nextnode=NULL;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    printf("\n the deleted node is : %d\t-->\t%p",nextnode->data,nextnode->next);
    free(nextnode);
    count--;
}

void delete_before_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is empty , no deletion");
        return;
    }
    if(pos<=1||pos>count)
    {
        printf("\n Invalid position");
        return;
    }
    if(pos==2)
    {
        delete_at_begin();
        return;
    }
    struct node*prev=NULL;
    temp=head;
    int i=1;
    while(i<pos-1)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    printf("\n the deleted node is : %d\t-->\t%p",temp->data,temp->next);
    free(temp);
    count--;
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
        printf("\n %d \t --> \t %p",temp->data,temp->next);
        temp=temp->next;
    } while (temp!=head);
}

int main()
{
    int pos,data,choice;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. deleteion at begin");
        printf("\n 3. deletion at end");
        printf("\n 4. deletion at specific position");
        printf("\n 5. deletion after a position");
        printf("\n 6. deletion before a position");
        printf("\n 7. display");
        printf("\n 8. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : delete_at_begin();
                        break;
            case 3  : delete_at_end();
                        break;
            case 4  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        delete_at_specific_pos(pos);
                        break;
            case 5  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        delete_after_pos(pos);
                        break;
            case 6  : printf("\n enter the position :");
                        scanf("%d",&pos);
                        delete_before_pos(pos);
                        break;
            case 7  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 8  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
}