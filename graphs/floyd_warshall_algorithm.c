#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX

struct node
{
    int src;
    int dest;
    int wt;
};


int **floyd_marshall(int v, int e, struct node edges[e]);
int min(const int a, const int b);

int **floyd_marshall(int v, int e, struct node edges[e])
{
    int **cost = (int **)malloc(v * sizeof(int *));
    for(int i=0;i<v;i++)
    {
        cost[i] = (int *)malloc(v * sizeof(int));
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
            {
                cost[i][j] = 0;
            }
            else
            {
                cost[i][j] = INFINITY;
            }
        }
    }

    for(int i=0;i<e;i++)
    {
        int source = edges[i].src;
        int destination = edges[i].dest;
        int weight = edges[i].wt;

        cost[source][destination] = weight;
    }
    printf("\n The cost matrix is : \n");
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            printf("%16d  ",cost[i][j]);
        }
        printf("\n");
    }

    for(int via = 0; via < v; via++)
    {
        for(int i =0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(cost[i][via] != INFINITY && cost[via][j] != INFINITY)
                {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if( cost[i][j] == INFINITY)
            {
                cost[i][j] = -1;
            }
        }
    }

    return cost;
}

int min(const int a, const int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

int main()
{
    int v,e;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&v);

    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&e);

    struct node  edges[e];
    printf("\n enter the edges in the graph (source - destination - weight) : ");
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&edges[i].src, &edges[i].dest, &edges[i].wt);
    }

    printf("\n The edges are : \n");
    for(int i=0; i<e; i++)
    {
        printf("%d - %d - %d\n",edges[i].src, edges[i].dest, edges[i].wt);
    }

    int **cost_matrix = floyd_marshall(v,e,edges);


    printf("\n The resultant cost matrix is : \n");
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            printf("%4d ",cost_matrix[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<v; i++)
    {
        free(cost_matrix[i]);
    }
    free(cost_matrix);
    return 0;
}