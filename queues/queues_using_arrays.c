#include<stdio.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;


void enqueue(int data)
{
    if(rear>=MAX-1)
    {
        printf("\n Queue Overflow");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        queue[++rear]=data;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("\n Queue underflow");
        return;
    }
    else if(front==rear)
    {
        printf("\n the deleted element is : %d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n the deleted element is : %d",queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the queue is empty");
        return;
    }
    else
    {
        printf("\n the queue elements are : ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n the total no.of elements are : %d",rear-front+1);
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the queue is empty");
        return;
    }
    printf("\n the front element is : %d",queue[front]);
}

void rear_element()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the queue is empty");
        return;
    }
    printf("\n the rear element is : %d",queue[rear]);
}


void isEmpty()
{
    if(front==-1 && rear==-1)
    {
        printf("\n IT IS EMPTY");
    }
    else
    {
        printf("\n NOT EMPTY");
    }
}

void isFull()
{
    if(rear==MAX-1)
    {
        printf("\n IT IS FULL");
    }
    else
    {
        printf("\n NOT FULL");
    }
}


int main()
{
    int data,choice;
    while(1)
    {
        printf("\n 1. enqueue");
        printf("\n 2. dequeue");
        printf("\n 3. display");
        printf("\n 4. peek / front");
        printf("\n 5. rear");
        printf("\n 6. isEmpty");
        printf("\n 7. isFull");
        printf("\n 8. exit");
        printf("\n\n enter your choice : ");
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
            case 5  : rear_element();
                        break;
            case 6  : isEmpty();
                        break;
            case 7  : isFull();
                        break;
            case 8  : return 0;
            default : printf("\n Invalid choice");
        }   
    }
    return 0;
}