// GfG-Problem Link: https://bit.ly/3QwPVsi

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
void add_edge(struct graph *g, int src, int dest);

int is_cycle_detection(struct graph *g, int vertices)
{
    int counter=0;

    int *queue=(int *)malloc(vertices * sizeof(int));
    int front=0,rear=0;

    int *in_degree=(int *)malloc(vertices * sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        in_degree[i]=0;
    }

    for(int i=0;i<vertices;i++)
    {
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            in_degree[temp->data]++;
            temp=temp->next;
        }
    }

    printf("\n The in-degree array is : ");
    for(int i=0;i<vertices;i++)
    {
        printf("%d ",in_degree[i]);
    }

    for(int i=0;i<vertices;i++)
    {
        if(in_degree[i]==0)
        {
            queue[rear++]=i;
        }
    }

    while(front < rear)
    {
        int current=queue[front++];
        counter++;

        struct node *temp=g->head[current];
        while(temp!=NULL)
        {
            in_degree[temp->data]--;
            
            if(in_degree[temp->data] == 0)
            {
                queue[rear++]=temp->data;
            }
            temp=temp->next;
        }
    }

    free(queue);
    free(in_degree);

    if( counter != vertices)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void add_edge(struct graph *g, int src, int dest)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation for node is failed");
        exit(EXIT_FAILURE);
    }

    newnode->data=dest;
    newnode->next=g->head[src];
    g->head[src]=newnode;
}

int main()
{
    int vertices,edges;
    printf("\n enter the no of vertices and edges in the graph : \n");
    scanf("%d %d",&vertices,&edges);
    
    if(vertices <= 0 || vertices >= MAX || edges <= 0 || edges >= MAX)
    {
        printf("\n Invalid input... exiting..!");
        return 0;
    }

    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n memory allocation for graph is failed");
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

    printf("\n The adjacency list is : \n");
    for(int i=0; i<vertices; i++)
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
        printf("\n The graph doesn't contain a cycle");
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

    return 0;
}