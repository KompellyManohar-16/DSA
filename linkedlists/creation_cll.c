#include<stdio.h>
#include<stdlib.h>
 
 struct node
 {
    int data;
    struct node *next;
 };
 struct node *head=NULL;
 struct node *newnode=NULL;
 struct node *temp=NULL;

int count=0;

 int main()
 {
    int choice;
    while(1)
    {
        printf("\n Do you want to add a node (0/1) ? :");
        scanf("%d",&choice);
        if(choice==1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return 0;
            }
            printf("\n enter the data :");
            scanf("%d",&newnode->data);
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
        else
        {
            printf("\n no more nodes will be added");
            break;
        }
    }
    if(head==NULL)
    {
        printf("\n the list is empty");
        printf("\n the head is : %p",head);
        return 0;
    }
    printf("\n the nodes are : ");
    printf("\n the data \t --> \t the address");
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %d \t --> \t %p",temp->data,temp->next);
        temp=temp->next;
    }while(temp!=head);
    printf("\n the total no.of nodes are : %d",count);
    return 0;
 }