#include<stdio.h>
#include<stdlib.h>
int main()
{
    int choice,count=0;
    struct node
    {
        int data;
        struct node* next;
    };
    struct node* head,*temp,*newnode;
    head=NULL;
    newnode=NULL;
    temp=NULL;
    while(1)
    {
        printf("\n Do you want to creat a node (0/1) ? :");
        scanf("%d",&choice);
        if(choice==1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return 0;
            }
                printf("\nenter the data : ");
                scanf("%d",&newnode->data);
                newnode->next=NULL;
                if(head==NULL)
                {
                    head=newnode;
                    temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
             
        }
        else 
        {
            printf("\n no creation");
            break;
        }
    }
            temp=head;
            printf("\n the nodes values are : ");
            printf("\n the head is : %p",head);
            while(temp!=NULL)
            {
                printf("\n %d\t-->%p",temp->data,temp->next);
                temp=temp->next;
                count++;
            }
            printf("\n the total no.of nodes are : %d",count);
            printf("\n the size of head is : %d",sizeof(head));
            printf("\n the size of newnode is : %d",sizeof(newnode));
            printf("\n the size of struct node is : %d",sizeof(struct node));
    return 0;
}