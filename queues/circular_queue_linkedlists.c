#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node *front=NULL;
struct node *rear=NULL;
struct node *temp=NULL;
struct node *newnode=NULL;

void enqueue(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    rear->next=front;
}

void dequeue()
{
    if(front==NULL && rear==NULL)
    {
        printf("\n the queue is empty");
        return; 
    }
    temp=front;
    if(front==rear)
    {
        printf("\n the dequeue element is : %d --> %p",temp->data,temp->next);
        front=rear=NULL;
    }
    else
    {
        printf("\n the dequeue element is : %d --> %p",temp->data,temp->next);
        front=front->next;
        rear->next=front;
    }
    free(temp);
}

void display()
{
    if(front==NULL && rear==NULL)
    {
        printf("\n the queue is empty");
        return;
    }
    printf("\n the queue elements are : ");
    temp=front;
    int count=0;
    do
    {
        printf("\n %d --> %p",temp->data,temp->next);
        temp=temp->next;
        count++;
    } while (temp!=front);
    printf("\n the total no of elements are : %d",count);
}

void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("\n the queue is empty");
        return;
    }
    printf("\n the peek elements is : %d --> %p",front->data,front->next);
}

void free_queue()
{
    if(front==NULL && rear==NULL)
    {
        printf("\n the queue is empty");
        return;
    }
    struct node *nextnode;
    temp=front;
    do
    {
        nextnode=temp->next;
        free(temp);
        temp=nextnode;
    } while (temp!=front);
    front=rear=NULL;
    printf("\n the queue is freed");
}

int main()
{
    int data,choice;
    while(1)
    {
        printf("\n\n 1. enqueue");
        printf("\n 2. dequeue");
        printf("\n 3. display");
        printf("\n 4. peek");
        printf("\n 5. free queue");
        printf("\n 6. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        enqueue(data);
                        break;
            case 2  : dequeue();
                        break;
            case 3  : display();
                        break;
            case 4  : peek();
                        break;
            case 5  : free_queue();
                        break;
            case 6  : free_queue();
                        return 0;
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}