// GfG-Problem Link: https://bit.ly/3PvBfsm

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node 
{
    int data;
    struct node *next;
};

struct graph 
{
    struct node *head[MAX];
};

int *topological_sort(struct graph *g, int vertices);
void dfs(int current, struct graph *g, int *visited, int *stack, int *top);

int *topological_sort(struct graph *g, int vertices)
{
    int *stack=(int *)malloc(vertices * sizeof(int));
    int top=-1;

    int *visited=(int *)malloc(vertices * sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
    }

    for(int start=0; start < vertices; start++)
    {
        if( !visited[start] )
        {
            dfs(start,g,visited,stack, &top);
        }
    }
    int *result=(int *)malloc(vertices * sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        result[i]=stack[top--];
    }

    free(stack);
    free(visited);
    return result;
}

void dfs(int current, struct graph *g, int *visited, int *stack, int *top)
{
    visited[current]=1;
    struct node *next_vertex = g->head[current];
    while(next_vertex != NULL)
    {
        if( !visited[next_vertex->data] )
        {
            dfs(next_vertex->data, g, visited,stack,top);
        }
        next_vertex=next_vertex->next;
    }
    stack[++(*top)]=current;
}


void add_edge(struct graph *g, int src, int dest)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n Memory allocatoin failed");
        exit(EXIT_FAILURE);
    }
    newnode->data=dest;
    newnode->next=g->head[src];
    g->head[src]=newnode;
}

int main()
{
    int vertices,edges;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&vertices);
    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&edges);

    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n The memory allocation for the graph is failed");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<vertices;i++)
    {
        g->head[i]=NULL;
    }

    printf("\n enter the edges in the graph : \n");
    for(int i=0;i<edges;i++)
    {
        int src,dest;
        scanf("%d %d",&src,&dest);
        add_edge(g,src,dest);
    }

    printf("\n The adjacenct list is : \n");
    for(int i=0;i<vertices;i++)
    {
        printf("\n%d : ",i);
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            printf("%d - ",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }

    int *result=topological_sort(g,vertices);

    printf("\n The topological sort is : \n");
    for(int i=0;i<vertices;i++)
    {
        printf("%d ",result[i]);
    }

    for(int i=0;i<vertices;i++)
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
    free(result);

    return 0;
}