#include<stdio.h>
#define MAX 10

int deque[MAX];
int front=-1,rear=-1;

void enqueue_front(int data)
{
    if(front==(rear+1)%MAX)
    {
        printf("\n the deque is full");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[front]=data;
    }
    else if(front==0)
    {
        front=MAX-1;
        deque[front]=data;
    }
    else
    {
        front--;
        deque[front]=data;
    }
}

void enqueue_rear(int data)
{
    if(front==(rear+1)%MAX)
    {
        printf("\n the deque is full");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[rear]=data;
    }
    else if(rear==MAX-1)
    {
        rear=0;
        deque[rear]=data;
    }
    else
    {
        rear++;
        deque[rear]=data;
    }
}

void dequeue_front()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the deque is empty");
        return;
    }
    else if(front==rear)
    {
        printf("\n the deleted element is : %d",deque[front]);
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        printf("\n the deleted element is : %d",deque[front]);
        front=0;
    }
    else
    {
        printf("\n the deleted element is : %d",deque[front]);
        front++;
    }
}

void dequeue_rear()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the deque is empty");
        return;
    }
    else if(front==rear)
    {
        printf("\n the deleted element is : %d",deque[rear]);
        front=rear=-1;
    }
    else if(rear==0)
    {
        printf("\n the deleted element is : %d",deque[rear]);
        rear=MAX-1;
    }
    else
    {
        printf("\n the deleted element is : %d",deque[rear]);
        rear--;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the deque is empty");
        return;
    }
    printf("\n the deque elements are : ");
    int i=front;
    int count=0;
    while(i!=rear)
    {
        printf("%d\t",deque[i]);
        i=(i+1)%MAX;
        count++;
    }
    printf("%d",deque[rear]);
    printf("\n the total no.of elements are : %d",count+1);
    printf("\n %d  %d",front,rear);
}



void front_element()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the deque is empty");
        return;
    }
    printf("\n the front element is : %d",deque[front]);
}

void rear_element()
{
    if(front==-1 && rear==-1)
    {
        printf("\n the deque is empty");
        return;
    }
    printf("\n the rear element is : %d",deque[rear]);
}


int main()
{
    int data,choice;
    while(1)
    {
        printf("\n\n 1. enqueue_front");
        printf("\n 2. enqueue_rear");
        printf("\n 3. dequeue_front");
        printf("\n 4. dequeue_rear");
        printf("\n 5. display");
        printf("\n 6. front");
        printf("\n 7. rear");
        printf("\n 8. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        enqueue_front(data);
                        break;
            case 2  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        enqueue_rear(data);
                        break;
            case 3  : dequeue_front();
                        break;
            case 4  : dequeue_rear();
                        break;
            case 5  : display();
                        break;
            case 6  : front_element();
                        break;
            case 7  : rear_element();
                        break;
            case 8  : return 0;
            default : printf("\n Invalid choice");
        }
    }
    return 0;
}