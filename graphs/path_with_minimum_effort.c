// GfG-Problem Link: https://bit.ly/3dMBvq6
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX
#define MAX 100

struct queue_node 
{
    int diff;
    int row;
    int col;
    struct queue_node *next;
};

int minimum_effort(int row, int col, int arr[row][col]);
struct queue_node *enqueue(struct queue_node *pq,int d, int r, int c);
struct queue_node *dequeue(struct queue_node **pq);
int is_empty(struct queue_node *pq);
void free_queue(struct queue_node **pq);
int max(int a, int b);



int minimum_effort(int row, int col, int arr[row][col])
{
    int dist[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            dist[i][j]=INFINITY;
        }
    }

    // we start from row = 0 and col = 0 and absolute difference = 0
    struct queue_node *pq=NULL;
    pq = enqueue(pq,0,0,0);
    dist[0][0] = 0;

    int del_row[]={-1,0,1,0};
    int del_col[]={0,1,0,-1};

    while(!is_empty(pq))
    {
        struct queue_node *current = dequeue(&pq);
        int current_diff = current->diff;
        int c_row = current->row;
        int c_col = current->col;
        free(current);

        if(c_row == row-1 && c_col == col-1)
        {
            free_queue(&pq);
            return current_diff;
        }

        for(int i=0;i<4;i++)
        {
            int new_row = c_row + del_row[i];
            int new_col = c_col + del_col[i];

            if(new_row >= 0 && new_row < row && new_col >= 0 && new_col < col)
            {
                int new_effort =  max( abs(arr[c_row][c_col] - arr[new_row][new_col]) , current_diff );
                if(new_effort < dist[new_row][new_col])
                {
                    dist[new_row][new_col] = new_effort;
                    pq = enqueue(pq,new_effort,new_row,new_col);
                }
            }
        }
    }
    return -1;
}

struct queue_node *enqueue(struct queue_node *pq,int d, int r, int c)
{
    struct queue_node *newnode = (struct queue_node *)malloc(sizeof(struct queue_node));
    if(!newnode)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->diff = d;
    newnode->row = r;
    newnode->col = c;
    newnode->next = NULL;
    
    if(pq == NULL || pq->diff > d)
    {
        newnode->next = pq;
        pq = newnode;
    }
    else
    {
        struct queue_node *temp = pq;
        while(temp->next != NULL && temp->next->diff < d)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return pq;
}

struct queue_node *dequeue(struct queue_node **pq)
{
    if( (*pq) == NULL)   return NULL;

    struct queue_node *head = (*pq);
    (*pq) = (*pq)->next;
    return head;
}


int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int is_empty(struct queue_node *pq)
{
    if(pq == NULL)
    {
        return 1;
    }
    return 0;
}

void free_queue(struct queue_node **pq)
{
    if( (*pq) == NULL) return;

    struct queue_node *temp = (*pq);
    while(temp!=NULL)
    {
        struct queue_node *next = temp->next;
        free(temp);
        temp=next;
    }
    (*pq)=NULL;
}


int main()
{
    int row,col;
    printf("\n enter the no of rows and cols : ");
    scanf("%d %d",&row,&col);
    int arr[row][col];
    printf("\n enter the values of the array : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n The entered array is : \n");
    for (int  i = 0; i < row; i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    int result = minimum_effort(row, col, arr);
    printf("\n The minimum effort is : %d",result);

    return 0;
    
}