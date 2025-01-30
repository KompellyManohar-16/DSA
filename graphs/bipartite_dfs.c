// GfG-Problem Link: https://bit.ly/3SQQgId
// https://leetcode.com/problems/is-graph-bipartite/description/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int dfs(int current, int new_color, int **graph, int *color, int graph_size , int *graph_col_size);

int is_bipartite_graph(int **graph, int graph_size , int *graph_col_size)
{
    int *color=(int *)malloc(graph_size * sizeof(int));
    for(int i=0;i<graph_size;i++)
    {
        color[i]=-1;            //no color
    }

    for(int start=0; start < graph_size; start++)
    {
        if( color[start] == -1 )
        {
            if( dfs(start,0,graph,color,graph_size,graph_col_size) == 0)
            {
                printf("\n The color array is : \n");
                for(int i=0;i<graph_size;i++)
                {
                    printf("%d ",color[i]);
                }
                free(color);
                return 0;
            }
        }
    }
    
    printf("\n The color array is : \n");
    for(int i=0;i<graph_size;i++)
    {
        printf("%d ",color[i]);
    }
    free(color);
    return 1;
}

int dfs(int current, int new_color, int **graph, int *color, int graph_size , int *graph_col_size)
{
    color[current]=new_color;

    for(int i=0; i < graph_col_size[current]; i++)
    {
        int next_vertex=graph[current][i];
        if(color[next_vertex] == -1)
        {
           if( dfs(next_vertex,1-new_color,graph,color,graph_size,graph_col_size) == 0)
           {
            return 0;
           }
        }
        else if(color[current]==color[next_vertex])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int row;
    printf("\n enter the no or rows in the jagged matrix : ");
    scanf("%d",&row);
    if(row<=0 || row>MAX)
    {
        printf("\n Invalid input.. exiting..!");
        return 0;
    }

    int *col_size=(int *)malloc(row * sizeof(int));
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
    printf("\n enter the values of jagged matrix : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j< col_size[i];j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n The jagged matrix is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col_size[i];j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    if( is_bipartite_graph(arr,row,col_size))
    {
        printf("\n The graph is bipartite graph");
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
    free(col_size);

    return 0;
}