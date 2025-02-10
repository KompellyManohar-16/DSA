// GfG-Problem Link: https://bit.ly/3RGnHLH

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX
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

struct queue_node
{
    int data,weight;
};


int *shortest_path(struct graph *g, int v, int e, int source)
{
    int *dist=(int *)malloc(v * sizeof(int));
    for(int i=0;i<v;i++)
    {
        dist[i]=INFINITY;
    }

    struct queue_node queue[MAX];
    int front =0,rear=0;

    queue[rear].data=source;
    queue[rear].weight=0;
    rear++;
    
    dist[source]=0;

    while(front < rear)
    {
        struct queue_node current=queue[front++];
        int dt = current.data;
        int wt = current.weight;

        struct node *temp=g->head[dt];
        while(temp!=NULL)
        {
            if( wt+1 < dist[temp->data])
            {
                dist[temp->data] = wt+1;
                queue[rear].data = temp->data;
                queue[rear].weight = wt+1;
                rear++;
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
    return dist;
}

void create_graph(struct graph *g, int vertices, int edges)
{
    printf("\n enter the edges in the graph : ");
    for(int i=0;i<edges;i++)
    {
        int src,dest;
        scanf("%d %d",&src,&dest);

        struct node *newnode1=(struct node*)malloc(sizeof(struct node));
        struct node *newnode2=(struct node*)malloc(sizeof(struct node));

        if(newnode1==NULL || newnode2==NULL)
        {
            printf("\n memory allocation failed");
            exit(EXIT_FAILURE);
        }
        newnode1->data=dest;
        newnode1->next=g->head[src];
        g->head[src]=newnode1;

      
        newnode2->data=src;
        newnode2->next=g->head[dest];
        g->head[dest]=newnode2;
    }
}


int main()
{
    int no_of_vertices,no_of_edges;
    printf("\n enter the no of vertices and edges : ");
    scanf("%d %d",&no_of_vertices,&no_of_edges);
    if(no_of_vertices <= 0 || no_of_vertices >= MAX || no_of_edges <= 0 || no_of_edges >= MAX)
    {
        printf("\nInvalid input ...exiting...!");
        return 0;
    }

    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    for(int i=0;i<MAX;i++)
    {
        g->head[i]=NULL;
    }

    create_graph(g,no_of_vertices,no_of_edges);
    
    printf("\n The adjacency list of the graph is :\n");
    for(int i=0;i<no_of_vertices;i++)
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

    int source;
    printf("\n enter the source vertex : ");
    scanf("%d",&source);

    int *result=shortest_path(g,no_of_vertices,no_of_edges,source);
    printf("\n The shortes path from the source %d is : \n",source);
    for(int i=0;i<no_of_vertices;i++)
    {
        printf("%d ",result[i]);
    }

    for(int i=0;i<no_of_vertices;i++)
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

