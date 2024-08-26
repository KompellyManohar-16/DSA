#include<stdio.h>
#define MAX 10


int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data)
{
    if((rear+1)%MAX==front)
    {
        printf("\n Queue overflow");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        rear=(rear+1)%MAX;
        queue[rear]=data;
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
        front=(front+1)%MAX;
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
        int i=front;
        int count=0;
        while(i!=rear)
        {
            printf("\n %d",queue[i]);
            i=(i+1)%MAX;
            count++;
        }
        printf("\n %d",queue[rear]);
        printf("\n the total no.of elements are : %d",count+1);
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the queue is empty");
        return;
    }
    else
    {
        printf("\n the peek is : %d",queue[front]);
    }
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
        printf("\n 5. exit");
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
            case 5  : return 0;
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}