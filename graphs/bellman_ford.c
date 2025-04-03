#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX
struct node
{
    int src;
    int dest;
    int weight;
};

int *bellman_ford(int v, int e, struct node edges[e], int source);

int *bellman_ford(int v, int e, struct node edges[e], int source)
{
    int *dist = (int *)malloc(v * sizeof(int));
    if(!dist)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<v; i++)
    {
        dist[i] = INFINITY;
    }

    dist[source] = 0;

    for(int i=0; i<v-1; i++)
    {
        for(int j=0; j<e; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int wt = edges[j].weight;

            if(dist[u]!=INFINITY &&  dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(int i=0; i<e; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int wt = edges[i].weight;

        if(dist[u]!=INFINITY &&  dist[u] + wt < dist[v])
        {
            int *temp = (int *)malloc(1 * sizeof(int));
            temp[0] = -1;

            free(dist);
            return temp;
        }
    }

    return dist;

}

int main()
{
    int v,e;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&v);
    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&e);
    
    struct node edges[e];
    printf("\n enter the edges in the graph : ");
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    printf("\n The edges in the graph are : \n");
    for(int i=0;i<e;i++)
    {
        printf("\n%d %d %d", edges[i].src, edges[i].dest, edges[i].weight);
    }

    int source;
    printf("\n enter the source : ");
    scanf("%d",&source);

    int *result = bellman_ford(v,e,edges,source);

    if(result[0] == -1)
    {
        printf("\n Negative weight cycle detected");
    }
    else
    {
        for(int i=0; i<v; i++)
        {
            if(result[i] == INFINITY)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ",result[i]);
            }
        }
    }
    free(result);
    return 0;
}