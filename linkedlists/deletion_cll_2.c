#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

int count=0;

struct node *head=NULL;
struct node *newnode=NULL;
struct node *temp=NULL;


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

void delete_spec(int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
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
            struct node *end=head;
            while(end->next!=head)
            {
                end=end->next;
            } 
            head=head->next;
            end->next=head;
        }
        printf("\n the deleted node is : %d\t-->\t%p",temp->data,temp->next);
        free(temp);
        count--;
        return;
    }
    temp=head;
    struct node *prev=head;
    do
    {
        if(temp->data==value)
        {
            prev->next=temp->next;
            printf("\n the deleted node is : %d\t-->\t%p",temp->data,temp->next);
            free(temp);
            count--;
            return;
        }
        prev=temp;
        temp=temp->next;
    } while (temp!=head);
    printf("\n the specified node %d is not found in the list, no deletion",value);
}


void delete_after(int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    temp=head;
    struct node *nextnode=NULL;
    do
    {
        if(temp->data==value)
        {
            if(temp->next==head)
            {
                printf("\n the specified node %d is found but it is end of the list , no deletion",value);
                return;
            }
            nextnode=temp->next;
            temp->next=nextnode->next;
            printf("\n the deleted node is : %d\t-->\t%p",nextnode->data,nextnode->next);
            free(nextnode);
            count--;
            return;
        }
        temp=temp->next;
    }while(temp!=head);
    printf("\n the specified node %d is not found in the list, no deletion",value);
}


void delete_before(int value)
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        return;
    }
    if(head->data==value)
    {
        printf("\n the specified node %d is found but it is the beginning of the list, no deletion",value);
        return;
    }
    temp=head;
    struct node *end=head;
    struct node *prev=NULL;
    struct  node *node_to_delete=NULL;
    do
    {
        if(temp->data==value)
        {
            if(node_to_delete==head)
            {
                while(end->next!=head)
                {
                    end=end->next;
                }   
                head=head->next;
                end->next=head;
            }           
            else
            {
                prev->next=node_to_delete->next; 
            }
            printf("\n the deleted node is : %d\t-->\t%p",node_to_delete->data,node_to_delete->next);
            free(node_to_delete);
            count--;
            return;
        }
        prev=node_to_delete;
        node_to_delete=temp;
        temp=temp->next;
    } while (temp!=head);
    printf("\n the specified node %d is not found in the list, no deletion",value);
}



void display()
{
    if(head==NULL)
    {
        printf("\n the list is empty");
        printf("\n the head is %p",head);
        return;
    }
    printf("\n the nodes are : ");
    printf("\n the head is : %p",head);
    temp=head;
    do
    {
        printf("\n %d\t-->\t%p",temp->data,temp->next);
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
        printf("\n 3. deletion after a node");
        printf("\n 4. deletion before a node");
        printf("\n 5. display");
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
                        delete_spec(value);
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
}