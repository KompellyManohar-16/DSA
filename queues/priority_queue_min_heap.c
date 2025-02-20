#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct 
{
    int queue[MAX];
    int size;
}MinHeap;

void swap(int *a, int *b);
void heapify_up(MinHeap *pq, int index);
void heapify_down(MinHeap *pq, int index);
void enqueue(MinHeap *pq, int data);
int dequeue(MinHeap *pq);
void display(MinHeap *pq);
int peek(MinHeap *pq);

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(MinHeap *pq, int index)
{
    int parent=(index-1)/2;
    if(index > 0 && pq->queue[parent] > pq->queue[index])
    {
        swap(&pq->queue[parent], &pq->queue[index]);
        heapify_up(pq, parent);
    }
}

void heapify_down(MinHeap *pq, int index)
{
    int smallest=index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if( left < pq->size && pq->queue[left] < pq->queue[smallest] )
        smallest = left;
    
    if(right < pq->size && pq->queue[right] < pq->queue[smallest] )
        smallest = right;

    if(smallest != index)
    {
        swap(&pq->queue[index], &pq->queue[smallest]);
        heapify_down(pq, smallest);
    }
}

void enqueue(MinHeap *pq, int data)
{
    if(pq->size >= MAX)
    {
        printf("\n The Queue Overflow");
        return;
    }

    pq->queue[pq->size]=data;
    pq->size++;
    heapify_up(pq, pq->size-1);
}

int dequeue(MinHeap *pq)
{
    if(pq->size <= 0)
    {
        printf("\n Queue Underflow");
        return -1;
    }
    int deleted = pq->queue[0];
    pq->queue[0] = pq->queue[--(pq->size)];
    heapify_down(pq,0);

    return deleted;
}
void display(MinHeap *pq)
{
    printf("\n The size of priority queue is : %d",pq->size);
    if(pq->size == 0)
    {
        printf("\n The priority queue is empty");
        return;
    }
    printf("\n The Min Heap is : \n");
    for(int i=0; i<pq->size; i++)
    {
        printf("%d ",pq->queue[i]);
    }
}

int peek(MinHeap *pq)
{
    if(pq->size == 0)
    {
        printf("\n The Priority queue is empty");
        return -1;
    }
    return pq->queue[0];
}

int main()
{
    MinHeap pq;
    pq.size=0;

    int ch, data, del, min;

    while(1)
    {    
        printf("\n 1. enqueue");
        printf("\n 2. dequeue");
        printf("\n 3. display");
        printf("\n 4. peek");
        printf("\n 5. exit");
        printf("\n enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1  :   printf("\n enter the data to insert : ");
                        scanf("%d",&data);
                        enqueue(&pq,data);
                        break;

            case 2  :   del = dequeue(&pq);
                       if( del != -1)
                        {
                            printf("\n The deleted element is : %d",del);
                        }
                        break;

            case 3  :   display(&pq);
                        break;
                        
            case 4  :   min = peek(&pq);
                        printf("\n The Min element is : %d",min);
                        break;

            case 5  : printf("\n exiting..!");
                        exit(EXIT_SUCCESS);
            default : printf("\n Invalid choice.. please enter again\n");
        }
    }
    return 0;
}