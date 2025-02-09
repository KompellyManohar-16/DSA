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

int is_cycle_detection(struct graph *g, int vertices);
int dfs(int current, struct graph *g, int vertices, int *visited, int *path_visited);
void add_edge(struct graph *g, int src, int dest);

int is_cycle_detection(struct graph *g, int vertices)
{
    int *visited = (int *)malloc(vertices * sizeof(int));
    int *path_visited = (int *)malloc(vertices * sizeof(int));

    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
        path_visited[i]=0;
    }

    for(int start=0; start<vertices; start++)
    {
        if( !visited[start] )
        {
            if( dfs(start,g,vertices,visited,path_visited) == 1)
            {
                printf("\n The visited array is : \n");
                for(int i=0;i<vertices;i++)
                {
                    printf("%d ",visited[i]);
                }
                printf("\n The path_visited arrays is : \n");
                 for(int i=0;i<vertices;i++)
                {
                    printf("%d ",path_visited[i]);
                }

                free(visited);
                free(path_visited);
                return 1;
            }
        }
    }
    printf("\n The visited array is : \n");
    for(int i=0;i<vertices;i++)
    {
        printf("%d ",visited[i]);
    }
    printf("\n The path_visited arrays is : \n");
        for(int i=0;i<vertices;i++)
    {
        printf("%d ",path_visited[i]);
    }
    free(visited);
    free(path_visited);
    return 0;
}

int dfs(int current, struct graph *g, int vertices, int *visited, int *path_visited)
{
    visited[current]=1;
    path_visited[current]=1;
    
    struct node *next_vertex = g->head[current];

    while(next_vertex != NULL)
    {
        if( !visited[next_vertex->data] )
        {
            if( dfs(next_vertex->data,g,vertices,visited,path_visited) == 1 )
            {
                return 1;
            }

        }
        else if( visited[next_vertex->data] == 1 && path_visited[next_vertex->data] == 1 )
        {
            return 1;
        }
        next_vertex = next_vertex->next;
    }
    path_visited[current]=0;
    return 0;
}

void add_edge(struct graph *g, int src, int dest)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->data=dest;
    newnode->next=g->head[src];
    g->head[src]=newnode;
}

int main()
{
    int vertices,edges;
    printf("\n enter no of vertices in the graph : ");
    scanf("%d",&vertices);
    printf("\n enter no of edges in the graph : ");
    scanf("%d",&edges);

    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n memory allocation is failed for graph");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<vertices;i++)
    {
        g->head[i]=NULL;
    }
    
    printf("\n enter the edges in the graph ( source - destination) : ");
    for(int i=0;i<edges;i++)
    {
        int src,dest;
        scanf("%d %d",&src,&dest);
        add_edge(g,src,dest);
    }

    printf("\n The adjacency list is : \n");
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

    if( is_cycle_detection(g,vertices) )
    {
        printf("\n The graph contains a cycle");
    }
    else
    {
        printf("\n The graph doesn't contain cycle");
    }

    for(int i=0;i<vertices;i++)
    {
       struct node *temp = g->head[i];
       while(temp!=NULL)
       {
            struct node *next=temp->next;
            free(temp);
            temp=next;
       }
    }
    free(g);

    return 0;
}