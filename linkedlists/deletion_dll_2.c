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

void delete_specific(int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    if(head!=NULL&&head->data==value)
    {
        temp=head;
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
        free(temp);
        count--;
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            if(temp->next!=NULL)
            {
                temp->next->prev=temp->prev;
            }
            temp->prev->next=temp->next;
            printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
            free(temp);
            count--;
            return;
        }
        temp=temp->next;
    }
    printf("\n the node value is not found in the list , no deletion");
}

void delete_after(int value)
{
    if(head==NULL)
    {
        printf("\n the list  is empty");
        return;
    }
    struct node *nextnode=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            nextnode=temp->next;
            if(nextnode!=NULL)
            {
                if(nextnode->next!=NULL)
                {
                    nextnode->next->prev=temp;
                }
                temp->next=nextnode->next;
                printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",nextnode->prev,nextnode->data,nextnode->next);
                free(nextnode);
                count--;
                return;
            }
            printf("\n the given node is found but it is end of the list , no deletion");
            return;
        }
        temp=temp->next;
    }
    printf("\n the node is not found in the list");
}

void delete_before(int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    if(head!=NULL&&head->data==value)
    {
        printf("\n the given node is found but it is the starting of the  list , no node before it \n no deletion");
        return;
    }
    struct node *prevnode=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            prevnode=temp->prev;
            if(prevnode->prev!=NULL)
            {
                    prevnode->prev->next=temp;
            }
            else
            {
                head=temp;
            }
            temp->prev=prevnode->prev;
            printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",prevnode->prev,prevnode->data,prevnode->next);
            free(prevnode);
            count--;
            return;
        }
        temp=temp->next;
    }
    printf("\n the given node is not found in the list");
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
    int choice,data,value;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. delete a specific node");
        printf("\n 3. delete after a given node");
        printf("\n 4. delete before a given node");
        printf("\n 5. display");
        printf("\n 6. exit");
        printf("\n enter the your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : printf("\n enter the value : ");
                        scanf("%d",&value);
                        delete_specific(value);
                        break;
            case 3  : printf("\n enter the value : ");
                        scanf("%d",&value);
                        delete_after(value);
                        break;
            case 4  : printf("\n enter the value : ");
                        scanf("%d",&value);
                        delete_before(value);
                        break;
            case 5  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 6  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}