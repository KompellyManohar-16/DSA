// GfG-Problem Link: https://bit.ly/3dJdQXE

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX
#define MAX 100

struct node 
{
    int data;
    int weight;
    struct node *next;
};

struct graph
{
    struct node *head[MAX];
};

int *shortest_path(int **edges, int v, int e, int source);
void dfs(int current, struct graph *g, int *visited, int *stack, int *top);
void add_edge(struct graph *g, int src, int dest, int wt);


void add_edge(struct graph *g, int src, int dest, int wt)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed..exiting..!");
        exit(EXIT_FAILURE);
    }
    
    newnode->data=dest;
    newnode->weight=wt;
    newnode->next=g->head[src];
    g->head[src]=newnode;
}

int *shortest_path(int **edges, int v, int e, int source)
{
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n memory allocation failed.. for the graph !");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<v;i++)
    {
        g->head[i]=NULL;
    }

    for(int i=0;i<e;i++)
    {
        int src=edges[i][0];
        int dest=edges[i][1];
        int wt=edges[i][2];
        add_edge(g,src,dest,wt);
    }

    printf("\n The adjacency list of the graph is : \n");
    for(int i=0;i<v;i++)
    {
        printf("\n%d : ",i);
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            printf("%d %d - ",temp->data,temp->weight);
            temp=temp->next;
        }
        printf("NULL");
    }

    int *stack=(int *)malloc(v * sizeof(int));
    int top=-1;

    int *visited=(int *)malloc(v *sizeof(int));
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }

    for(int i=0;i<v;i++)
    {
        if( !visited[i] )
        {
            dfs(i,g,visited,stack,&top);
        }
    }   

    int *dist=(int *)malloc(v * sizeof(int));

    for(int i=0;i<v;i++)
    {
        dist[i]=INFINITY;
    }

    dist[source]=0;
    while(top >= 0)
    {
        int current=stack[top--];
        struct node *temp=g->head[current];
        while(temp!=NULL)
        {
            if( dist[current]!=INFINITY && ( dist[current] + temp->weight ) < dist[temp->data] )
            {
                dist[temp->data]=dist[current]+temp->weight;
            }
            temp=temp->next;
        }
    }

    for(int i=0;i<v;i++)
    {
        if(dist[i]==INFINITY)
        {
            dist[i]=-1;
        }
    }

    for(int i=0;i<v;i++)
    {
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            struct node *next=temp->next;
            free(temp);
            temp=next;
        }
    }
    free(g);
    free(stack);
    free(visited);

    return dist;
}

void dfs(int current, struct graph *g, int *visited, int *stack, int *top)
{
    visited[current]=1;

    struct node *next_vertex=g->head[current];
    while(next_vertex != NULL)
    {
        if( !visited[next_vertex->data] )
        {
            dfs(next_vertex->data, g, visited, stack, top);
        }
        next_vertex=next_vertex->next;
    }
    stack[++(*top)]=current;
}

int main()
{
    int no_of_vertices,no_of_edges;
    printf("\n enter the no of vertices and edges in the graph : ");
    scanf("%d %d",&no_of_vertices,&no_of_edges);
    if(no_of_vertices <=0 || no_of_vertices>=MAX || no_of_edges < 0 || no_of_edges >= MAX)
    {
        printf("\n Invalid input..exiting..1");
        return 0;
    }

    int **edges=(int **)malloc(no_of_edges * sizeof(int*));
    for(int i=0;i<no_of_edges;i++)
    {
        edges[i]=(int *)malloc(3 * sizeof(int));
    }

    printf("\n enter the edges in the graph with the weights : \n");
    for(int i=0;i<no_of_edges;i++)
    {
        scanf("%d %d %d",&edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("\n The edges with weight is : \n");
    for(int i=0;i<no_of_edges;i++)
    {
        printf("\n%d - %d %d",edges[i][0],edges[i][1],edges[i][2]);
    }

    int source;
    printf("\n enter the source vertex : ");
    scanf("%d",&source);

    int *result=shortest_path(edges,no_of_vertices,no_of_edges,source);

    printf("\n The shortest path from the source vertex %d is : \n",source);
    for(int i=0;i<no_of_vertices;i++)
    {
        printf("%d ",result[i]);
    }

    for(int i=0;i<no_of_edges;i++)
    {
        free(edges[i]);
    }
    free(edges);

    return 0;
}