#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
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
        newnode->next=head;
        newnode->prev=head;
    }
    else
    {
        newnode->next=head;
        newnode->prev=head->prev;
        head->prev->next=newnode;
        head->prev=newnode;   
    }
    count++;
}



void delete_specific(int value)
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
        return;
    }
    if(head->data==value)
    {
        temp=head;
        if(head->next==head)
        {
            head=NULL;
        }
        else
        {
            struct node *last=head->prev;
            head=head->next;
            last->next=head;
            head->prev=last;
        }
        printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
        free(temp);
        count--;
        return;
    }
    temp=head;
    do
    {
        if(temp->data==value)
        {
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
            free(temp);
            count--;
            return;
        }
        temp=temp->next;
    } while (temp!=head);
    printf("\n the specified node is not found in the list");
}

void delete_after(int value)
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
        return;
    } 
    temp=head;
    do
    {
        if(temp->data==value)
        {
            if(temp->next==head)
            {
                printf("\n the specified node is found but it is the end of the list, no deletion");
                return;
            }
                struct node *nextnode=temp->next;
                temp->next=nextnode->next;
                nextnode->next->prev=temp;
                printf("\n the deleted node is : %p \t <-- \t %d \t --> \t %p",nextnode->prev,nextnode->data,nextnode->next);
                free(nextnode);
                count--;
                return;
        }
        temp=temp->next;
    } while (temp!=head);
    printf("\n the specified node is not found in the list");
}

void delete_before(int value)
{
    if(head==NULL)
    {
        printf("\n the list is already empty");
        return;
    }
    if(head->data==value)
    {
        printf("\n the specified node is found but , it is the beginning  of the list, no deletion");
        return;
    }
    temp=head;
    do
    {
        if(temp->data==value)
        {
            struct node *prevnode=temp->prev;
            if(prevnode==head)
            {
                head=head->next;
            }
            temp->prev=prevnode->prev;
            prevnode->prev->next=temp;
            printf("\n the deleted node is : %p \t <-- \t %d \t --> %p",prevnode->prev,prevnode->data,prevnode->next);
            free(prevnode);
            count--;
            return;
        }
        temp=temp->next;
    } while (temp!=head);
    printf("\n the specified node is not found in the list");
}


void display()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        printf("\n the head is : %p",head);
        return;
    }
    printf("\n the list nodes are :");
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
        temp=temp->next;
    } while (temp!=head);
}



int main()
{
    int data,value,choice;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. deletion of specific node");
        printf("\n 3. deletion after the node");
        printf("\n 4. deletion before the node");
        printf("\n 5. diplay");
        printf("\n 6. exit");
        printf("\n enter your choice : ");
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