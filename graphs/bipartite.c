// GfG-Problem Link: https://bit.ly/3SQQgId
// https://leetcode.com/problems/is-graph-bipartite/description/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int is_bipartite_graph(int **graph,int graph_size, int *graph_col_size)
{

    int color[graph_size];      // color array  represents the color of each vertex in the graph
    for(int i=0;i<graph_size;i++)
    {
        color[i]=-1;                // -1 represents no color
    }

    int queue[MAX],front=0,rear=0;

    for(int start=0;start<graph_size;start++)
    {
        if( color[start] == -1)
        {
            front=rear=0;
            queue[rear++]=start;
            color[start]=0;                     // two colors : 0 and 1

            while(front < rear)
            {
                int current=queue[front++];

                for(int i=0; i < graph_col_size[current]; i++)
                {
                    int next_vertx=graph[current][i];

                    if(color[next_vertx] == -1)
                    {
                        color[next_vertx]=1-color[current];
                        queue[rear++]=next_vertx;
                    }
                    else if( color[current] == color[next_vertx] )
                    {
                        return 0;
                    }
                }
            }
        }
    }
    printf("\n The color arrays is : \n");
    for(int i=0;i<graph_size;i++)
    {
        printf("%d ",color[i]);
    }
    return 1;
}

int main()
{
    int row;
    printf("\n enter no of rows in the jagged array : ");
    scanf("%d",&row);
    if(row <= 0 || row > MAX)
    {
        printf("\n Invalid input.. exiting..!");
        return 0;
    }

    int col_size[row];
    printf("\n enter the column size of each row : ");
    for(int i=0;i<row;i++)
    {
        scanf("%d",&col_size[i]);
    }

    int **arr=(int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        arr[i]=(int *)malloc(col_size[i] * sizeof(int));
    }

    printf("\n enter the matrix : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col_size[i];j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n The entered matrix is : \n");
        for(int i=0;i<row;i++)
    {
        for(int j=0;j<col_size[i];j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    if( is_bipartite_graph(arr,row,col_size) )
    {
        printf("\n The graph is a bartite graph");
    }
    else
    {
        printf("\n The graph is not a bipartite graph");
    }

    for(int i=0;i<row;i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}