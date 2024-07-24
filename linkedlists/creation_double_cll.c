#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *temp=NULL;
struct node *head=NULL;
struct node *newnode=NULL;

int count=0;

int main()
{
    int choice,count=0;
    while(1)
    {
        printf("\n Do you want to create the node (o/1) ? : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return 0;
            }
            printf("\n enter the data : ");
            scanf("%d",&newnode->data);
            newnode->prev=NULL;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=newnode;
                temp=newnode;
                newnode->next=head;
                newnode->prev=head;
            }
            else
            {
                temp->next=newnode;
                newnode->prev=temp;
                newnode->next=head;
                head->prev=newnode;
                temp=newnode;
            }
            count++;
        }
        else
        {
            printf("\n no creation");
            break;
        }
    }
    if(head==NULL)
    {
        printf("\n the head is : %p",head);
        printf("\n the list is empty");
        return 0;
    }
    printf("\n the elements are : ");
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %p \t <-- \t %d \t --> \t %p",temp->prev,temp->data,temp->next);
        temp=temp->next;
    }while(temp!=head);
    printf("\n the total no.of nodes are : %d",count);
    return 0;
}