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
        newnode->prev=temp;
        temp->next=newnode;
    }
    count++;
}

void delete_at_begin()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    temp=head;
    head=head->next;
    if(head!=NULL)
    {
        head->prev=NULL;
    }
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->prev!=NULL)
    {
        temp->prev->next=NULL;
    }
    else
    {
        head=NULL;
    }
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_spec(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
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
    if(temp->next!=NULL)
    {
        temp->next->prev=temp->prev;
    }
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
    count--;
}

void delete_after_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
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
    if(nextnode->next!=NULL)
    {
        nextnode->next->prev=temp;
    }
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",nextnode->prev,nextnode->data,nextnode->next);
    free(nextnode);
    count--;
}

void delete_before_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
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
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
    free(temp);
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
    temp=head;
    printf("\n the nodes are : ");
    printf("\n the prev \t <-- \t the data \t --> \t the next");
    printf("\n the head is : %p",head);
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
        printf("\n 1. insert");
        printf("\n 2. delete at begin");
        printf("\n 3. delete at end");
        printf("\n 4. delete at specific position");
        printf("\n 5. delete after a position");
        printf("\n 6. delete before a position");
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
                        delete_at_spec(pos);
                        break;
            case 5  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        delete_after_pos(pos);
                        break;
            case 6  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        delete_before_pos(pos);
                        break;
            case 7  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 8  : exit(0);
            default : printf("\n INVALID CHOICE");
        }
    }
    return 0;
}
