// GfG-Problem Link: https://bit.ly/3KeZZ7j

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

struct queue_node
{
    int distance;
    int node;
    struct queue_node *next;
};


void create_graph(struct graph *g, int edges);
int *dijkstra(struct graph *g, int vertices, int source);
int is_Empty(struct queue_node *pq);
struct queue_node * enqueue(struct queue_node *pq, int d, int n);
struct queue_node *dequeue(struct queue_node **pq);

int *dijkstra(struct graph *g, int vertices, int source)
{
    int *dist = (int *)malloc(vertices * sizeof(int));
    for(int i=0; i<vertices; i++)
    {
        dist[i]=INFINITY;
    }

    struct queue_node *pq = NULL;
    pq=enqueue(pq,0,source);

    dist[source]=0;

    while(!is_Empty(pq))
    {
        struct queue_node *current = dequeue(&pq);

        int current_vertex = current->node;
        int current_distance = current->distance;
        free(current);

        struct node *temp = g->head[current_vertex];
        while(temp != NULL)
        {
            if( temp->weight + current_distance < dist[temp->data] )
            {
                dist[temp->data] = temp->weight + current_distance;
                pq = enqueue(pq, dist[temp->data], temp->data);
            }
            temp = temp->next;
        }
    }
    return dist;
}

int is_Empty(struct queue_node *pq)
{
    if(pq == NULL)
    {
        return 1;
    }
    return 0;
}

struct queue_node * enqueue(struct queue_node *pq, int d, int n)
{
    struct queue_node *newnode = (struct queue_node *)malloc(sizeof(struct queue_node));
    if(!newnode)
    {
        printf("\n memory allocation failde..\n");
        exit(EXIT_FAILURE);
    }
    newnode->distance = d;
    newnode->node = n; 
    newnode->next = NULL;

    if(pq == NULL || pq->distance > d)
    {
        newnode->next = pq;
        pq = newnode;
    }
    else
    {
        struct queue_node *temp = pq;
        while(temp->next != NULL && temp->next->distance < d)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return pq;
}
struct queue_node *dequeue(struct queue_node **pq)
{
    if( (*pq) == NULL )
    {
        return NULL;
    }
    else
    {
        struct queue_node *head = (*pq);
        (*pq)=(*pq)->next;

        return head;
    }
}

void create_graph(struct graph *g, int edges)
{
    printf("\n enter the edges in the graph with the weight(src -- dest -- weight) : ");
    for(int i=0; i<edges; i++)
    {
        int src,dest,wt;
        scanf("%d %d %d",&src,&dest,&wt);
        
        struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
        if(!newnode1)
        {
            printf("\n memory allocation failde..\n");
            exit(EXIT_FAILURE);
        }
        newnode1->data = dest;
        newnode1->weight = wt;
        newnode1->next = g->head[src];
        g->head[src] = newnode1;

        struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
        if(!newnode2)
        {
            printf("\n memory allocation failde..\n");
            exit(EXIT_FAILURE);
        }
        newnode2->data = src;
        newnode2->weight = wt;
        newnode2->next = g->head[dest];
        g->head[dest] = newnode2;
    }
}

int main()
{
    int vertices, edges;
    printf("\n enter the no or vertices in the graph : ");
    scanf("%d",&vertices);
    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&edges);

    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    for(int i=0; i<vertices; i++)
    {
        g->head[i]=NULL;
    }

    create_graph(g,edges);

    printf("\n The adjacency list is : \n");
    for(int i=0; i<vertices; i++)
    {
        printf("\n%d : ",i);
        struct node *temp = g->head[i];
        while(temp!=NULL)
        {
            printf("%d %d --> ",temp->data,temp->weight);
            temp=temp->next;
        }
        printf("NULL");
    }
    
    int source;
    printf("\n enter the source : ");
    scanf("%d",&source);

    int *dist = dijkstra(g,vertices,source);

    printf("\nThe shortest path distances from the source are : \n");
    for(int i=0; i<vertices; i++)
    {
        printf("\n Vertex %d : %d",i,dist[i]);
    }

    for(int i=0; i<vertices; i++)
    {
        struct node *temp = g->head[i];
        while(temp!=NULL)
        {
            struct node *next = temp->next;
            free(temp);
            temp=next;
        }
    }
    free(g);
    free(dist);
    return 0;
}