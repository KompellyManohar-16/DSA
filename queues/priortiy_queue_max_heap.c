#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    int queue[MAX];
    int size;
}MaxHeap;

void insert(MaxHeap *pq, int data);
void heapify_up(MaxHeap *pq, int index);
void swap(int *a, int *b);
int delete_max(MaxHeap *pq);
void heapify_down(MaxHeap *pq, int index);
void display(MaxHeap *pq);
int peek(MaxHeap *pq);


void insert(MaxHeap *pq, int data)
{
    if(pq->size >= MAX)
    {
        printf("\n Queue Overflow..!");
        return;
    }

    pq->queue[pq->size] = data;
    pq->size++;
    heapify_up(pq, pq->size-1);
}

void heapify_up(MaxHeap *pq, int index)
{
    if(index > 0)
    {
        int parent = (index - 1)/2;
        if(pq->queue[parent] < pq->queue[index])
        {
            swap(&pq->queue[parent], &pq->queue[index]);
            heapify_up(pq, parent);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int delete_max(MaxHeap *pq)
{
    if(pq->size <= 0)
    {
        printf("\n Queue Underflow..!");
        return -1;
    }
    int deleted_element = pq->queue[0];
    pq->queue[0] = pq->queue[--(pq->size)];
    heapify_down(pq,0);
    return deleted_element;
}

void heapify_down(MaxHeap *pq, int index)
{
    int largest = index;
    int left_child = (2 * index) + 1;
    int right_child = (2 * index) + 2;

    if( left_child < pq->size && pq->queue[left_child] > pq->queue[largest])
    {
        largest = left_child;
    }
    if( right_child < pq->size && pq->queue[right_child] > pq->queue[largest])
    {
        largest = right_child;
    }

    if(largest != index)
    {
        swap(&pq->queue[largest],&pq->queue[index]);
        heapify_down(pq, largest);
    }
}

void display(MaxHeap *pq)
{
    if(pq->size <= 0)
    {
        printf("\n Priority queue is empty");
        return;
    }
    printf("\n");
    for(int i=0; i<pq->size; i++)
    {
        printf("%d ",pq->queue[i]);
    }
}

int peek(MaxHeap *pq)
{
    if(pq->size <= 0)
    {
        printf("\n The Priority queue is empty");
        return -1;
    }
    return pq->queue[0];
}

int main()
{
    MaxHeap pq;
    pq.size = 0;

    int choice, data, deleted, max;
    while(1)
    {
        printf("\n\n 1. insert");
        printf("\n 2. delete_max");
        printf("\n 3. display");
        printf("\n 4. peek");
        printf("\n 5. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("\n enter the data to insert : ");
                        scanf("%d",&data);
                        insert(&pq,data);
                        break;

            case 2  : deleted = delete_max(&pq);
                        if(deleted != -1)
                        {
                            printf("\n The deleted element is : %d",deleted);
                        }
                        break;

            case 3  : display(&pq);
                        break;

            case 4  : max = peek(&pq); 
                        if(max != -1)
                        {
                            printf("\n The max element is : %d",max);
                        }
                        break;

            case 5  : printf("\n exiting...!");
                        exit(EXIT_SUCCESS);

            default : printf("\n Invalid input.. please enter again");
        }
    }
    return 0;
}