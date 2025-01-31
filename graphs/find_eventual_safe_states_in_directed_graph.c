// GfG-Problem Link: https://bit.ly/3C90n59
// https://leetcode.com/problems/find-eventual-safe-states/description/

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

int *find_safe_states(struct graph *g, int vertices, int *safe_count);
int dfs(int current, struct graph *g, int *visited, int *path_visited, int *safe);
void add_edge(struct graph *g, int src, int dest);

int *find_safe_states(struct graph *g, int vertices, int *safe_count)
{
    int *visited=(int *)malloc(vertices * sizeof(int));
    int *path_visited=(int *)malloc(vertices * sizeof(int));
    int *safe=(int *)malloc(vertices * sizeof(int));
    int *result=(int *)malloc(vertices * sizeof(int));

    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
        path_visited[i]=0;
        safe[i]=0;
        result[i]=0;
    }

    for(int start=0; start < vertices; start++)
    {
        if( !visited[start] )
        {
            dfs(start,g,visited,path_visited,safe);
        }
    }

    *safe_count=0;
    for(int i=0;i<vertices;i++)
    {
        if(safe[i]==1)
        {
            result[(*safe_count)++]=i;
        }
    }
    free(visited);
    free(path_visited);
    free(safe);

    return result;
}

int dfs(int current, struct graph *g, int *visited, int *path_visited, int *safe)
{
    visited[current]=1;
    path_visited[current]=1;

    struct node *next_vertex=g->head[current];
    while(next_vertex != NULL)
    {
        if( !visited[next_vertex->data] )
        {
            if( dfs(next_vertex->data,g,visited,path_visited,safe) == 1 )
            {
                safe[current]=0;
                return 1;
            }
        }
        else if( visited[next_vertex->data] == 1 && path_visited[next_vertex->data] == 1)
        {
            safe[current]=0;
            return 1;
        }
        next_vertex=next_vertex->next;
    }
    safe[current]=1;
    path_visited[current]=0;
    return 0;
}

void add_edge(struct graph *g, int src, int dest)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
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
    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&edges);

    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<vertices;i++)
    {
        g->head[i]=NULL;
    }


    printf("\n enter the edges in the graph : ");
    for(int i=0;i<edges;i++)
    {
        int src,dest;
        scanf("%d %d",&src,&dest);
        add_edge(g,src,dest);
    }

    printf("\n The adjacency list is : \n");
    for (int  i = 0; i < vertices; i++)
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
    int safe_count=0;
    int *result=find_safe_states(g,vertices,&safe_count);

    printf("\n The safe states are : \n");
    for(int i=0;i<safe_count;i++)
    {
        printf("%d ",result[i]);
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
    free(result);

    return 0;
}