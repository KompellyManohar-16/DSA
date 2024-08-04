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
    newnode->prev=NULL;
    newnode->next=NULL;
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

void delete_at_begin()
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
        return;
    }
    temp=head;
    if(head->next==head)
    {
        head=NULL;
    }
    else
    {
        head=head->next;
        head->prev=temp->prev;        
        temp->prev->next=head;
    }
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
        return;
    }
    temp=head->prev;
    if(head->next==head)
    {
        head=NULL;
    }
    else
    {
        head->prev=temp->prev;
        temp->prev->next=head;

    }
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_specific_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
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
    int i=1;
    temp=head;
    while(i<pos)
    {
       temp=temp->next;
       i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
    count--;
}

void delete_after_position(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
        return;
    }
    if(pos<1||pos>=count)
    {
        printf("\n Invalid position");
        return;
    }
    struct node *nextnode=NULL;
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    nextnode->next->prev=temp;
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",nextnode->prev,nextnode->data,nextnode->next);
    free(nextnode);
    count--;
}

void delete_before_position(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
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
    struct node *prevnode=NULL;
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    prevnode=temp->prev;
    temp->prev=prevnode->prev;
    prevnode->prev->next=temp;
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",prevnode->prev,prevnode->data,prevnode->next);
    free(prevnode);
    count--;
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


int main()
{
    int data,pos,choice;
    while(1)
    {
        printf("\n\n 1. insert");
        printf("\n 2. deletion at begin");
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
            case 1  : printf("\n enter the data to insert : ");
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
                        delete_after_position(pos);
                        break;
            case 6  : printf("\n enter the position : ");       
                        scanf("%d",&pos);
                        delete_before_position(pos);
                        break;
            case 7  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break; 
            case 8  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
    return;
}