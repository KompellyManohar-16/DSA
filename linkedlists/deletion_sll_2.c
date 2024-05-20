#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
struct node * newnode=NULL;

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
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    count++;
 }

void delete_spec(int value)
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
        printf("\n the deleted node is :\n %d \t --> \t %p",temp->data,temp->next);
        free(temp);
        count--;
        return;
    }
    temp=head;
    struct node *prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            prev->next=temp->next;
            printf("\n the deleted node is :\n %d \t --> \t %p",temp->data,temp->next);
            free(temp);
            count--;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("\n the given node is not found in the list");
}

void delete_after(int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
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
                temp->next=nextnode->next;   
                printf("\n the deleted node is \n %d \t --> \t %p",nextnode->data,nextnode->next);                  
                free(nextnode);                                
                count--; 
                return;
            }     
            printf("\n the given node value is found but there is no next node , it is the end of the list");                 
            return;                                  
        }
        temp=temp->next;
    }
    printf("\n the given node value is not found in the list");
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
        printf("\n the given node value is found but there is no previous node to it, \n it is the begining of the list ");
        return;
    }
    struct node *prev=NULL;
    struct node *current=NULL;
    struct node *nextnode=NULL;
    nextnode=head;
    while(nextnode!=NULL)
    {
        if(nextnode->data==value)
        {
            if(prev==NULL)
            {
                head=nextnode;
            }
            else
            {
                prev->next=nextnode;
            }
            printf("\n the deleted node is : \n %d \t --> \t %p",current->data,current->next);
            free(current);
            count--;
            return;
        }
        prev=current;
        current=nextnode;
        nextnode=nextnode->next;
    }
    printf("\n the given node value is not found in the list");
}

void display()
{
    if(head==NULL)
    {
        printf("\n the head is : %p",head);
        printf("\n the list is empty");
        return;
    }
    temp=head;
    printf("\n the head is : %p",head);
    printf("\n the data \t --> \t the address");
    while(temp!=NULL)
    {
        printf("\n %d \t --> \t %p",temp->data,temp->next);
        temp=temp->next;
    }
}


int main()
{
    int choice,data,value;
    while(1)
    {
        printf("\n 1.insert");
        printf("\n 2.delete a specific given node");
        printf("\n 3.delete after a given node");
        printf("\n 4.delete before a given node");
        printf("\n 5.display");
        printf("\n 6.exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data to insert : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : printf("\n enter the node value : ");
                        scanf("%d",&value);
                        delete_spec(value);
                        break;
            case 3  : printf("\n enter the node value : ");
                        scanf("%d",&value);
                        delete_after(value);
                        break;
            case 4  : printf("\n enter the node value : ");
                        scanf("%d",&value);
                        delete_before(value);
                        break;
            case 5  : display();
                        printf("\n the total no.of nodes are : %d",count);
                        break;
            case 6  : exit(0);
            default : printf("\n Invalid  choice");
        }
    }
    return 0;
}