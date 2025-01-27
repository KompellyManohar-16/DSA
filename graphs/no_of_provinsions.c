// click this link for description
// GfG-Problem Link: https://bit.ly/3yR3dIB

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int no_of_provision(int **arr, int v)
{
    int queue[MAX],front=0,rear=0;
    int visited[MAX]={0};

    int count=0;

    for(int start=0;start<v;start++)
    {
        if( !visited[start] )
        {
            count++;
            front=rear=0;
            queue[rear++]=start;
            visited[start]=1;

            while(front < rear)
            {
                int current = queue[front++];
                printf("%d ",current);

                for(int i=0;i<v;i++)
                {
                    if( arr[current][i] == 1 && !visited[i] )
                    {
                        queue[rear++]=i;
                        visited[i]=1;
                    }
                } 
            }
        }
    }
    return count;
}

int main()
{
    int v;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&v);
    
    int **arr=(int **)malloc(v * sizeof(int *));
    for(int i=0;i<v;i++)
    {
        arr[i]=(int *)malloc(v * sizeof(int));
    }
    printf("\n enter the adjacency matrix : \n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int count=no_of_provision(arr,v);
    printf("\n The no of provisions are : %d",count);
    return 0;
}