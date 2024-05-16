#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data; 
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
struct node* temp=NULL;
struct node* newnode=NULL;
int main()
{
    int choice,count=0;
    while(1)
    {
        printf("\n Do you want create a node (0/1) ?: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failded");
            }
            else
            {
                printf("\n enter the data : ");
                scanf("%d",&newnode->data);
                newnode->next=NULL;
                newnode->prev=NULL;
                if(head==NULL)
                {
                    head=newnode;
                    temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    newnode->prev=temp;
                    temp=newnode;
                }
            }
        }
        else
        {
            printf("\n No creation");
            break;
        }
    }

    temp=head;
    printf("\n the elements are : ");
    printf("\n the prev \t <-- \t the data \t --> the next");
    printf("\n the head is : %p",head);
    while(temp!=NULL)
    {
        printf("\n %p \t <-- \t %d \t --> %p",temp->prev,temp->data,temp->next);
        temp=temp->next;
        count++;
    }
    printf("\n the total no.of nodes are : %d",count);
    return 0;
}